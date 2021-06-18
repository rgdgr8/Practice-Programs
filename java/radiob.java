import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

class Main
{
	private static JRadioButton rb1;
	private static JRadioButton rb2;
	private static JRadioButton rb3;
	private static JLabel l;

	private static class MyListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			if(rb1.isSelected()) l.setText(rb1.getText());
			else if(rb2.isSelected()) l.setText(rb2.getText());
			else if(rb3.isSelected()) l.setText(rb3.getText());
			else l.setText("One option must be selected");
		}
	}

	public static void main(String[] args)
	{
		JFrame f = new JFrame("Choose Elective Subject");

		rb1 = new JRadioButton("Subject1");
		rb2 = new JRadioButton("Subject2");
		rb3 = new JRadioButton("Subject3");
		ButtonGroup bg = new ButtonGroup();
		bg.add(rb1);
		bg.add(rb2);
		bg.add(rb3);
		
		JPanel p =new JPanel();
		p.add(rb1);	
		p.add(rb2);
		p.add(rb3);

		JButton b = new JButton("OK");
		b.addActionListener(new MyListener());
		p.add(b);

		//f.setSize(350,350);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		l = new JLabel("");
		f.add(p);
		f.add(l,BorderLayout.NORTH);
		f.pack();
		f.setVisible(true);
	}
}


