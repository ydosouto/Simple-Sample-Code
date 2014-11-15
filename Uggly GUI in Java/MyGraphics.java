import javax.swing.JFrame;
import java.awt.Graphics;
import java.awt.*;
import java.awt.event.*;

class MyGraphics extends JFrame
{
	Container c;
	int lastX, lastY;
	
	MyGraphics(int width, int height)
	{
		super("Smile white board...");
		c = getContentPane();
		c.setBackground(Color.white);
		lastX = 0;
		lastY = 0;
		
		addMouseListener(new PositionRecorder());
		addMouseMotionListener(new LineDrawer());
		
		setSize(width, height);
		setVisible(true);
	}
	void record(int x, int y)
	{
		lastX = x;
		lastY = y;
	}
	
	public void paint(Graphics g)
	{
		super.paint(g);
		int star_x[] = {5,65,81,97,164,112,133,83,27,52} ;
		int star_y[] = {88,88,30,88,88,121,179,145,179,121} ;
	
		g.setColor(Color.red);
		g.fillPolygon(new Polygon(star_x, star_y, star_x.length));
	
		int house_x[] = {40, 40, 200, 200, 120};
		int house_y[] = {300, 380, 380, 300, 220};
		g.setColor(Color.black);
		g.fillPolygon(new Polygon(house_x, house_y, house_x.length));
		
		g.setColor(Color.green);
		g.setFont( new Font("Algerian", Font.BOLD, 30));
		g.drawString("My house", 200, 420);
		
		g.setColor(Color.CYAN);
		g.fillRect(100, 330, 40, 50);
	}
	
	private class PositionRecorder extends MouseAdapter
	{
		public void mouseEntered(MouseEvent e)
		{
			record( e.getX(), e.getY() );
		}
		public void mousePressed(MouseEvent e)
		{
			record( e.getX(), e.getY() );
		}
	}
	private class LineDrawer extends MouseMotionAdapter
	{
		public void mouseDragged(MouseEvent e)
		{
			int x = e.getX();
			int y = e.getY();
			Graphics g = getGraphics();
			g.setColor(Color.blue);
			g.drawLine(x, y, lastX, lastY);
			record(x,y);
	
		}
	}
}