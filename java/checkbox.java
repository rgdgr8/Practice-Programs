import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

class Main
{
	private static JCheckBox rb1;
	private static JCheckBox rb2;
	private static JCheckBox rb3;
	private static JLabel l;

	private static class MyListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			String x = "";
			if(rb1.isSelected()) x += rb1.getText()+" ";
			if(rb2.isSelected()) x += rb2.getText()+" ";
			if(rb3.isSelected()) x += rb3.getText();
			if(x.equals("")) {l.setText("One option must be selected");return;}
			l.setText(x);
		}
	}

	/*private static class MyListener2 implements ActionListener{
		public void actionPerformed(ActionEvent e){
			JCheckBox x = (JCheckBox)e.getSource();
			if(x.isSelected())
			 l.setText(x.getText()+" is selected");
			else
			 l.setText(x.getText()+" is deselected");
		}
	}*/
	private static class MyListener2 implements ItemListener{
		public void itemStateChanged(ItemEvent e){
			JCheckBox x = (JCheckBox)e.getItem();
			if(e.getStateChange()==ItemEvent.SELECTED);
			 //l.setText(x.getText()+" is selected");
			else
			 l.setText(x.getText()+" is deselected");
		}
	}

	public static void main(String[] args)
	{
		JFrame f = new JFrame("Choose Elective Subject");

		rb1 = new JCheckBox("Subject1");
		rb2 = new JCheckBox("Subject2");
		rb3 = new JCheckBox("Subject3");
		rb1.addItemListener(new MyListener2());
		rb2.addItemListener(new MyListener2());
		rb3.addItemListener(new MyListener2());
		
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

		f.setSize(350,350);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		l = new JLabel("");
		f.add(p);
		f.add(l,BorderLayout.NORTH);
		f.setVisible(true);
	}
}
