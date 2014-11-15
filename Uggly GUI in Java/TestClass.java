import java.awt.Color;

public class TestClass {

	public static void main(String[] arg)
	{
		MyJFrame frame = new MyJFrame(Constants.TITLE);
		frame.setVisible(true);
		frame.setSize(Constants.WEIGHT, Constants.HEIGTH);
		frame.setLocationRelativeTo(null);
		frame.getContentPane().setBackground(Color.white);
		
		MyButton buttons = new MyButton(frame);
		buttons.addButtons();
		
	}
}
