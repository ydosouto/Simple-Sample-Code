import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import java.awt.Container;

public class DisplayText
{
   public JTextArea text;

   public DisplayText( String title, String info)
   {
		MyJFrame f = new MyJFrame(title);
		Container c = f.getContentPane();

		text = new JTextArea(info);

		JScrollPane sp = new JScrollPane(text);
		c.add( sp );

      	f.setBounds(100,200, 500, 400 );
	   	f.setVisible(true);
   }

}