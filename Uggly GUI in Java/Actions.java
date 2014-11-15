import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.StringSelection;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.io.IOException;
import java.net.URL;

class Actions implements ActionListener
{	
	static DisplayText dt;
	String selectedText = "";

	public void actionPerformed(ActionEvent e)
	{	
		String url = "";
		if (e.getActionCommand().equalsIgnoreCase("New"))
		{
			dt = new DisplayText("Untitled..... ", "");
		}
		else if(e.getActionCommand().equalsIgnoreCase("Open"))
		{
			BasicFile f = new BasicFile();
			f.selectFile();
			dt = new DisplayText(f.getName(), f.getContent());
		}
		else if (e.getActionCommand().equalsIgnoreCase("Copy"))
		{
			try{
				selectedText =dt.text.getSelectedText();
			}
			catch(IllegalArgumentException a)
			{
				 a.printStackTrace();
			}
			StringSelection selection = new StringSelection(selectedText);
			Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
			clipboard.setContents(selection, selection);     		     
		}
		else if (e.getActionCommand().equalsIgnoreCase("Paste"))
		{
			dt.text.paste();
		}
		else if(e.getActionCommand().equalsIgnoreCase("Browser"))
		{
			Browser browser = new Browser("My Web Browser");
		}
		else if(e.getActionCommand().equalsIgnoreCase("Drawing"))
		{
			MyGraphics graphics = new MyGraphics(800,640);
		}
		else if (e.getSource() == Browser.text)
		{
		      url = Browser.text.getText();
		}
	    try {
	      Browser.pane.setPage(new URL(url));
	      Browser.text.setText(url);
	    } catch(IOException ioe) {
	    }
		

	}
}

