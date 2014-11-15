import urllib2, json
from BeautifulSoup import BeautifulSoup
import json

#Need this because some of the case numbers come accompanied by an *. 
def stripBadChar(word):
    return word.strip("*").strip()

website = "http://www.cdc.gov/vhf/ebola/outbreaks/history/chronology.html"

#Handles HTML call errors 
def safe_call(website):
    try:
        return urllib2.urlopen(website).read()
    except urllib2.URLError, e:
        if hasattr(e,'reason'):
            print "We failed to reach a server"
            print "Reason", e.reason
        elif hasattr(e,"code"):
            print "The server couldn't fulfill the request."
            print "Error code: ", e.code
        return None

#Parses website to obtain the table
def get_table(handler):
    soup = BeautifulSoup(handler)
    return soup.findAll('table')

#Gets rows and colums of the table to obtain the info I need for the data set
def makelist(table):
    result = []
    soup = BeautifulSoup(table)
    allrows = soup.findAll("tr")
    for row in allrows:
        result.append([])
        allcols = row.findAll('td')
        for col in allcols:
            thetext = ''.join(col.findAll(text=True))
            
            result[-1].append(thetext)
    return result

#Getting total count of ebola cases per country            
def country_victim(a_list):
    dic = {}
    del a_list[0]
    for item in a_list:
        if not dic.has_key(item[0]):
            dic[item[0]] = stripBadChar(str(item[2]))
        else:
            dic[item[0]] =  int(stripBadChar(str(dic[item[0]]))) + int(stripBadChar(str(item[2])))
    del dic["Multiple countries"] #This is showing the cases for the current outbreak, not of interest for this data set
    return dic

#HTML website is poorly written, some countries are refered in different ways
#This functions unifies keys that represent the same thing into single key.
def avoid_redundancy(dic):
    keys = dic.keys()
    for key in keys:
        if key.__contains__("Zaire") or key.__contains__("Democratic Republic of the Congo"):
            new_key = "Democratic Republic of the Congo (DRC)"
            dic[new_key] = int(dic[key]) + int(dic.get(new_key,0))
            del dic[key]
    return dic

#I will use this csv file for my final project
def write_file(finaldic):
    file = open("victim_per_country.csv","w")
    file.write("country, cases\n")
    keys = finaldic.keys()
    for key in keys:
        string = key.encode('utf-8') + "," + str(finaldic[key])  + "\n" 
        file.write(string)
    file.close()  

#Writes to a json file that is specifically formated to work with the bubbles of D3
#I know it is ugly but javascript code needs this format    
def write_json(final_dic):
    json_dic = {}
    json_dic["name"]= "ebola"
    json_dic["children"] = []
    a_list = []
    b_list = []
    c_list = []
    a_dic = {}
    a_dic["name"]= "cases"
    a_dic["children"] =[]
    a_list.append(a_dic)
    b_dic = {}
    b_dic["name"]= "country"
    b_dic["children"] =[]
    c_list.append(b_dic)
    keys = final_dic.keys()
    for key in keys:
        dic = {}
        dic["name"] = key.encode('utf-8')
        dic["size"] = final_dic[key]
        b_list.append(dic)
    b_dic["children"] = b_list    
    a_dic["children"] = c_list
    json_dic["children"] = a_list
    json.dump(json_dic, open("flare.json", 'wb'))

         

handler = safe_call(website)
handler = handler.replace("(asymptomatic)","") #sometimes cases numbers are specified to be asymptomatic, not using this
table = str(get_table(handler))
finaldic = country_victim(makelist(table))
dic = avoid_redundancy(finaldic)
write_file(dic)
write_json(dic)



    
