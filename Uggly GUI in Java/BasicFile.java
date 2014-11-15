import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;


public class BasicFile {

	File f;
	JFileChooser choose;
	
	void display(String msg, String s)
	{
		JOptionPane.showMessageDialog(null, msg, s, JOptionPane.INFORMATION_MESSAGE);
	}
	
	public String getName() {
		return f.getName();
	}

	public String getContent() {
		String str = " ";
		try {
			Scanner sc = new Scanner(f.getAbsoluteFile());
			while(sc.hasNextLine()){
			    str = str + '\n' + sc.nextLine();                     
			}
			sc.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		return str.substring(2);
	}

	public void selectFile() {
		choose = new JFileChooser(".");
		boolean fileWasSelected = false;
		while (!fileWasSelected)
		{
		int status = choose.showOpenDialog(null);
		try
		{
			if (status!= JFileChooser.APPROVE_OPTION) throw new IOException();
			f = choose.getSelectedFile();
			fileWasSelected = true;
			if(!f.exists()) throw new FileNotFoundException();
		}
		catch (FileNotFoundException e)
		{
			display(e.toString(), "File not found....");
		}
		catch (IOException e)
		{
			display("Please Select a File", "Please Select a File" );
		}
		}
		
	}	

}


    
    

