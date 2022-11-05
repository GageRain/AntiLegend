package code;

import java.awt.AlphaComposite;
/** �������������������鼮���ɾ���йصĴ���(������������)
 * @author �ι���
 */
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.plaf.basic.BasicBorders.FieldBorder;

import user.Account;

public class BookMenu {

	public static void main(String[] args) throws IOException {
		new CheckLentMenu();
	}
}

/**
 * ���ͼ��Ĵ�������
 * 
 */
class AddBookMenu extends Account {
	// �����������
	final static JFrame f_add = new JFrame("����鼮��Ϣ");
	// ������ǩ����
	static JLabel lb_name = new JLabel("�鼮����");
	static JLabel lb_author = new JLabel("����");
	static JLabel lb_price = new JLabel("�۸�");
	static JLabel lb_number = new JLabel("����");
	static JLabel lb_blank = new JLabel("                       ");
	// �����ı������
	static JTextField tf_name = new JTextField(24);
	static JTextField tf_author = new JTextField(11);
	static JTextField tf_price = new JTextField(4);
	static JTextField tf_number = new JTextField(4);
	// ������ť����
	static JButton bt_confirm = new JButton("ȷ��");
	static JButton bt_quit = new JButton("ȡ��");

	// flag_add���ڱ���Ƿ���ӳɹ�
	static int flag_add;

	public AddBookMenu() {
		flag_add = 0;
		// ���ô�������
		f_add.setBounds(500, 200, 350, 125);
		f_add.setLayout(new FlowLayout());
		f_add.setResizable(false); // ��ֹ�ı䴰���С
		f_add.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);

		// �����¼�
		// ȷ�����
		bt_confirm.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				// ��⼸����Ҫ��Ϣ�ǹ�Ϊ�գ����Ϊ�գ��������
				if (!(tf_name.getText().trim().contentEquals("") || tf_number.getText().trim().contentEquals(""))) {
					try {
						if (flag_add == 0) {
							BookDemo.addBook();
						}
					} catch (IOException e1) {
						e1.printStackTrace();
					}
					// �۸����Ŀת��Ϊ����
					int pri = Integer.parseInt(tf_price.getText().trim());
					int num = Integer.parseInt(tf_number.getText().trim());
					// ����һ���鼮���󣬴洢������Ϣ
					Book b = new Book();
					b.setName(tf_name.getText().trim());
					b.setID(Account.ID);
					b.setAuthor(tf_author.getText().trim());
					b.setNumber(num);
					b.setPrice(pri);

					File book = new File("books//" + b.bID + ".txt");
					OutputStreamWriter osw;
					try {
						osw = new OutputStreamWriter(new FileOutputStream(book));
						osw.write(b.checkToString(b));
						osw.close();
						flag_add += 1;
					} catch (FileNotFoundException e1) {
						e1.printStackTrace();
					} catch (IOException e1) {
						e1.printStackTrace();
					}

					if (flag_add == 1) {
						f_add.dispose();
						f_add.setVisible(false);
						try {
							BookDemo.uploadBooks();
						} catch (IOException e1) {
							e1.printStackTrace();
						}
						new NoteMenu("��ӳɹ�", "�鼮��Ϣ�Ѿ���ӳɹ���");
					}

				}
				// ���ĳ��Ϣ��дΪ��
				else {
					new NoteMenu("�������", "���벻��Ϊ�գ�������������룡");
				}

			}
		});
		// �˳���Ӱ��
		bt_quit.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				f_add.dispose();
				f_add.setVisible(false);
			}
		});

		// ��Ӵ������
		f_add.add(lb_name);
		f_add.add(tf_name);
		f_add.add(lb_author);
		f_add.add(tf_author);
		f_add.add(lb_price);
		f_add.add(tf_price);
		f_add.add(lb_number);
		f_add.add(tf_number);
		f_add.add(bt_confirm);
		f_add.add(lb_blank);
		f_add.add(bt_quit);

		// ���ô��ڿɼ�
		f_add.setVisible(true);
	}
}

/**
 * ��ѯ�Ѿ����ģ�δ�黹��ͼ��Ĵ�������
 * 
 */
class CheckLentMenu{
	// �����������
	final static JFrame f_check = new JFrame("δ�黹�鼮��Ϣ");
	// ������ǩ����
	static JLabel lb_lent = new JLabel("��ǰ�ѽ���δ�黹���鼮��Ϣ");
	static JLabel lb_blank = new JLabel("                       ");
	static JLabel lb_blank2 = new JLabel("                       ");
	// �����ı������
	static JTextArea ta_lent = new JTextArea(27, 48);
	
	public CheckLentMenu() throws IOException {

		// ���ô�������
		f_check.setBounds(500, 100, 550, 550);
		f_check.setLayout(new FlowLayout());
		f_check.setResizable(false); // ��ֹ�ı䴰���С
		f_check.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
		
		// �����ı�
		BookDemo.uploadBooks();
		String text = ""; // �ı�����ı�
		File folder = new File("books");
		File[] bks = folder.listFiles();
		for(File f: bks) {
			if(!(f.getName().contentEquals("BookList.txt"))) {
				String name = f.getName();
				int id = Integer.parseInt(name.substring(0, name.indexOf('.')));	
				Book b = Account.books[id];
				if(b.bNumber2 >= 1) text += b.checkToString(b);
			}
		}
		if(text.contentEquals("")) text = "��";
		ta_lent.setLineWrap(true); //�����Զ����й��� 
		ta_lent.setWrapStyleWord(true); // ������в����ֹ���
		ta_lent.setText(text);
		
		// ��ֹ����
		ta_lent.addKeyListener(new KeyAdapter() {
			@Override
			public void keyTyped(KeyEvent e) {
				e.consume();
			}
		});

		// ��Ӵ������
		f_check.add(lb_blank);
		f_check.add(lb_lent);
		f_check.add(lb_blank2);
		f_check.add(ta_lent);

		// ���ô��ڿɼ�
		f_check.setVisible(true);
	}
}

/**
 * ����ͼ��Ĵ�������
 * 
 */
class BorrowBookMenu {
	// �����������
	final static JFrame f_borrow = new JFrame("�����鼮");
	// ������ǩ����
	static JLabel lb_id = new JLabel("������Ҫ���ĵ��鼮��ţ�");
	static JLabel lb_blank = new JLabel("                       ");
	// �����ı������
	static JTextField tf_id = new JTextField(4);
	// ������ť����
	static JButton bt_confirm = new JButton("ȷ��");
	static JButton bt_quit = new JButton("ȡ��");
	static int flag1 = 0;

	public BorrowBookMenu() {
		// ���ô�������
		f_borrow.setBounds(500, 200, 250, 100);
		f_borrow.setLayout(new FlowLayout());
		f_borrow.setResizable(false); // ��ֹ�ı䴰���С
		f_borrow.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);

		// �����¼�
		// ȷ�����
		bt_confirm.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				// ��⼸����Ҫ��Ϣ�ǹ�Ϊ�գ����Ϊ�գ��������
				if (!(tf_id.getText().trim().contentEquals(""))) {
					try {
						flag1 = BookDemo.borrowBook(Integer.parseInt(tf_id.getText().trim()));
					} catch (NumberFormatException e1) {
						e1.printStackTrace();
					} catch (IOException e1) {
						e1.printStackTrace();
					}

					if(flag1 == 1) {
						f_borrow.dispose();
						f_borrow.setVisible(false);
						new NoteMenu("���ĳɹ�", "���鼮�ѽ��ĳɹ���");
					}
					else if(flag1 == 0) new NoteMenu("����ʧ��", "���鼮���޴��飡");
				
				}
				// ���ĳ��Ϣ��дΪ��
				else {
					new NoteMenu("�������", "���벻��Ϊ�գ�������������룡");
				}
			}
		});
		// �˳���Ӱ��
		bt_quit.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				f_borrow.dispose();
				f_borrow.setVisible(false);
			}
		});

		// ��Ӵ������
		f_borrow.add(lb_id);
		f_borrow.add(tf_id);
		f_borrow.add(bt_confirm);
		f_borrow.add(lb_blank);
		f_borrow.add(bt_quit);

		// ���ô��ڿɼ�
		f_borrow.setVisible(true);
	}
}

/**
 * �黹ͼ��Ĵ�������
 * 
 */
class ReturnBookMenu {
	// �����������
	final static JFrame F_return = new JFrame("�黹�鼮");
	// ������ǩ����
	static JLabel lb_id = new JLabel("������Ҫ�黹���鼮��ţ�");
	static JLabel lb_blank = new JLabel("                       ");
	// �����ı������
	static JTextField tf_id = new JTextField(4);
	// ������ť����
	static JButton bt_confirm = new JButton("ȷ��");
	static JButton bt_quit = new JButton("ȡ��");
	static int flag2 = 0;
	public ReturnBookMenu() {
		// ���ô�������
		F_return.setBounds(500, 200, 250, 100);
		F_return.setLayout(new FlowLayout());
		F_return.setResizable(false); // ��ֹ�ı䴰���С
		F_return.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);

		// �����¼�
		// ȷ�����
		bt_confirm.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				// ��⼸����Ҫ��Ϣ�ǹ�Ϊ�գ����Ϊ�գ��������
				if (!(tf_id.getText().trim().contentEquals(""))) {
					try {
						flag2 = BookDemo.returnBook(Integer.parseInt(tf_id.getText().trim()));
					} catch (NumberFormatException e1) {
						e1.printStackTrace();
					} catch (IOException e1) {
						e1.printStackTrace();
					}
					
					if(flag2 == 1) {
						F_return.dispose();
						F_return.setVisible(false);
						new NoteMenu("�黹�ɹ�", "���鼮�ѹ黹�ɹ���");
					}
					else if(flag2 == 0) new NoteMenu("�黹ʧ��", "������δ�黹�ĸ��鼮��");
				
				}
				// ���ĳ��Ϣ��дΪ��
				else {
					new NoteMenu("�������", "���벻��Ϊ�գ�������������룡");
				}
			}
		});
		// �˳���Ӱ��
		bt_quit.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				F_return.dispose();
				F_return.setVisible(false);
			}
		});

		// ��Ӵ������
		F_return.add(lb_id);
		F_return.add(tf_id);
		F_return.add(bt_confirm);
		F_return.add(lb_blank);
		F_return.add(bt_quit);

		// ���ô��ڿɼ�
		F_return.setVisible(true);
	}
}


/**
 * ɾ��ͼ��Ĵ�������
 * 
 */
class DeleteBookMenu{
	// �����������
	final static JFrame f_delete = new JFrame("ɾ���鼮��Ϣ");
	// ������ǩ����
	static JLabel lb_id = new JLabel("������Ҫɾ�����鼮��ţ�");
	static JLabel lb_blank = new JLabel("                       ");
	// �����ı������
	static JTextField tf_id = new JTextField(4);
	// ������ť����
	static JButton bt_confirm = new JButton("ȷ��");
	static JButton bt_quit = new JButton("ȡ��");
	
	static int flag;

	public DeleteBookMenu() {
		// ���ô�������
		f_delete.setBounds(500, 200, 250, 100);
		f_delete.setLayout(new FlowLayout());
		f_delete.setResizable(false); // ��ֹ�ı䴰���С
		f_delete.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);

		// �����¼�
		// ȷ�����
		bt_confirm.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				// ��⼸����Ҫ��Ϣ�ǹ�Ϊ�գ����Ϊ�գ��������
				if (!(tf_id.getText().trim().contentEquals(""))) {
					try {
						flag = BookDemo.deleteBook(Integer.parseInt(tf_id.getText()));
					} catch (IOException e1) {
						e1.printStackTrace();
					}
					if (flag == 1) {
						f_delete.dispose();
						f_delete.setVisible(false);
						new NoteMenu("ɾ���ɹ�", "�鼮��Ϣ�Ѿ�ɾ���ɹ���");
					}
				}
				// ���ĳ��Ϣ��дΪ��
				else {
					new NoteMenu("�������", "���벻��Ϊ�գ�������������룡");
				}
			}
		});
		// �˳���Ӱ��
		bt_quit.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				f_delete.dispose();
				f_delete.setVisible(false);
			}
		});

		// ��Ӵ������
		f_delete.add(lb_id);
		f_delete.add(tf_id);
		f_delete.add(bt_confirm);
		f_delete.add(lb_blank);
		f_delete.add(bt_quit);

		// ���ô��ڿɼ�
		f_delete.setVisible(true);
	}
}

/**
 * �����ڵ����ú���ʾ
 */
class NoteMenu {
	// str1Ϊ���ڱ��⣻str2Ϊ��������
	public NoteMenu(String str1, String str2) {
		// ���ô�������
		JFrame f = new JFrame(str1);
		f.setBounds(500, 190, 350, 65);
		f.setLayout(new FlowLayout());
		f.setResizable(false); // ��ֹ�ı䴰���С
		f.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
		// ��Ӻ��������
		JLabel label = new JLabel(str2);
		label.setFont(new Font("����", Font.BOLD, 16));
		f.add(label);
		// ���ô����¼�
		f.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				f.setAlwaysOnTop(false);
				f.dispose();
				f.setVisible(false);
			}
		});
		// ���ô���ɼ�
		f.setAlwaysOnTop(true);
		f.setVisible(true);

	}
}