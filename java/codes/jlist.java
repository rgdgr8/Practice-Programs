import java.awt.event.*;
//import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;

class Main
{
	/*private static class MyListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			System.out.println("OK button to be implemented. Bye for now.");
			System.exit(0);
		}
	}*/
	private static JList<String> jl;
	private static JLabel label;

	public static void main(String[] args)
	{
		JFrame f = new JFrame("List");
		JPanel p =new JPanel();
		
		String[] x = new String[100];
		for(int i=0;i<100;i++)
			x[i] = ("Option"+i);
		jl = new JList<>(x);
		//jl.setSelectionMode(ListSelectionModel.SINGLE_INTERVAL_SELECTION);
		jl.addListSelectionListener(new MyListener());
		JScrollPane jsp = new JScrollPane(jl);
		p.add(jsp);

		label = new JLabel("Select at least one option");
		p.add(label);
		/*JButton b = new JButton("OK");
		b.addActionListener(new MyListener());
		p.add(b);*/
		f.add(p);

		f.setSize(400,400);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//f.pack();
		f.setVisible(true);
	}
	private static class MyListener implements ListSelectionListener{
		public void valueChanged(ListSelectionEvent e){
			if(!e.getValueIsAdjusting()){
				StringBuilder x = new StringBuilder("");
				for(String s : jl.getSelectedValuesList())
					x.append(s).append("\n");
				label.setText(x.toString()+"are selected");
			}
		}
	}
}


