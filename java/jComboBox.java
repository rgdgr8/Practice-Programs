import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

class X{
	int a;
	X(int a){this.a=a;}
	public String toString(){return String.valueOf(a);}
}	

class Main
{
	private static JComboBox<X> jcb;
	private static class MyListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			System.out.println(e.getSource());
			System.out.println(jcb.getSelectedItem());
		}
	}

	public static void main(String[] args)
	{
		JFrame f = new JFrame("Choose Elective Subject");
		JPanel p =new JPanel();
		
		X[] x = new X[100];
		for(int i=0;i<100;i++)
			x[i] = new X(i);
		jcb = new JComboBox<>(x);
		jcb.setEditable(true);
		jcb.addActionListener(new MyListener());
		//JScrollPane jsp = new JScrollPane(jl);
		p.add(jcb);

		JButton b = new JButton("OK");
		//b.addActionListener(new MyListener());
		p.add(b);

		//f.setSize(350,350);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.add(p);
		f.pack();
		f.setVisible(true);
	}
}


