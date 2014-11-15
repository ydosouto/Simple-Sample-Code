import java.awt.BorderLayout;
import java.awt.Container;
import java.io.IOException;
import javax.swing.JEditorPane;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.event.HyperlinkEvent;
import javax.swing.event.HyperlinkListener;

public class Browser implements HyperlinkListener {

	static JTextField text;
	static JEditorPane pane;
	
	Browser(String title)
	{

		MyJFrame f = new MyJFrame(title);
		Container c = f.getContentPane();
		f.setVisible(true);
		f.setSize(800,640 );
		f.setLocationRelativeTo(null);
		
		text = new JTextField("http://yoannadosouto1.appspot.com/");
		text.setEditable(true);
		text.addActionListener(new Actions());
		c.add(text, BorderLayout.NORTH);
		
		pane = new JEditorPane();
		pane.setEditable(false);
		pane.addHyperlinkListener(this);
		try {
			pane.setPage(text.getText());
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		JScrollPane sp = new JScrollPane(pane);
		c.add(sp, BorderLayout.CENTER);
		
	}

	@Override
	 public void hyperlinkUpdate(HyperlinkEvent event) {
	    if (event.getEventType() == HyperlinkEvent.EventType.ACTIVATED) {
	      try {
	    	pane.setPage(event.getURL());
	        text.setText(event.getURL().toExternalForm());
	      } catch(IOException ioe) {
	       
	      }
	    }
	  }
}
