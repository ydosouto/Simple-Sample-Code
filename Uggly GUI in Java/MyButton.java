import java.awt.Container;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.io.FileNotFoundException;
import java.io.FileReader;
import javax.swing.ImageIcon;
import javax.swing.JButton;

public class MyButton extends JButton 
{
	MyJFrame f;
	JButton b;

	MyButton(MyJFrame f)
	{
		this.f = f;
	} 
	
	public void addButtons()
	{
		
		Container content = f.getContentPane();
		
		GridBagLayout gbag = new GridBagLayout(); 
		
		GridBagConstraints constraints = new GridBagConstraints();
		
		content.setLayout(gbag);
		String[] button = Constants.BUTTONS;
		
		for (int i = 0; i < button.length; i++)
		   {
			b = new JButton(button[i]);
		
			switch(i)
			{
				 case 0:
					 	b = new JButton(button[i]);
					 	constraints.gridx = 0; 
						constraints.gridy = 0; 
						constraints.insets = new Insets(0,0,0,0);
						b.addActionListener(new Actions());
					break;
				 	case 1:
						b = new JButton(button[i]);
						constraints.gridx = 1;
						constraints.gridy = 0;	  
						constraints.insets = new Insets(20,0,20,200);	
						
					break; 
					case 2:
						try
						{
							FileReader f = new FileReader(button[i]);
							b = new JButton( new ImageIcon(button[i]));
						} 
						catch (FileNotFoundException ex) 
						{
							b.setText("Image is not in the correct folder");
							b.setSize(50, 20);
						}
						constraints.gridx = 0;  
						constraints.gridy = 1;
						constraints.insets = new Insets(20,300,0,0);

					break;
					
				 	case 3:
						b = new JButton(button[i]);
						constraints.gridx = 0;
						constraints.gridy = 2;	  
						constraints.ipadx = 200;
						b.addActionListener(new Actions());	
					break; 
				}
			gbag.setConstraints(b, constraints);
		    content.add(b);
		 }
	}   
}
