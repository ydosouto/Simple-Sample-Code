import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JRadioButton;

public class MyJFrame extends JFrame
{
	JMenuBar menubar;
	JMenu f;
	JMenuItem mi;
	JCheckBoxMenuItem cb;
	JRadioButton jrb;

	public MyJFrame(String title)
	{
		super(title);
		menubar = new JMenuBar();
		setJMenuBar(menubar);

		buildMenu();
	}

	void buildMenu()
	{
		for (int i = 0; i < Constants.MENU.length; i++)
		{	
			f = new JMenu(Constants.MENU[i]);

			switch(i)
			{
			case 0: 
				for (int j = 0; j < Constants.FILES.length; j++)
					if (Constants.FILES[j].equals("-"))
						f.addSeparator();
					else
					{
						f.add(mi = new JMenuItem(Constants.FILES[j]));
						mi.addActionListener(new Actions());
					}
				break;

			case 1:
				for (int k = 0; k < Constants.TOOL.length; k++)
					if (Constants.TOOL[k].equals("Edit"))
					{
						f.addSeparator();
						JMenu m = new JMenu(Constants.TOOL[k]); 
						for (int l = 0; l < Constants.EDIT.length; l++)
						{
							m.add(jrb = new JRadioButton(Constants.EDIT[l]));
							jrb.addActionListener(new Actions());
						}
						f.add(m);
					}
					else
					{
						f.add(cb = new JCheckBoxMenuItem(Constants.TOOL[k]));
						cb.addActionListener(new Actions());
					}
				break;
			}
			menubar.add(f);
		}

		this.addWindowListener(new java.awt.event.WindowAdapter() {
			@Override
			public void windowClosing(java.awt.event.WindowEvent windowEvent) {
				JOptionPane.showMessageDialog(null, "The window is closing", "Ugly GUI",
						JOptionPane.INFORMATION_MESSAGE);   
			}
		});
	}
}
