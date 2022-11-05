package user;

import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import user.Account;
import user.Login;

public class Register extends Account {
	// �����������
	final static JFrame f_register = new JFrame("����Աע�����");

	// ������ǩ����
	static JLabel label_username = new JLabel("�����������û�����");
	static JLabel label_password = new JLabel("�������������룺     ");
	static JLabel label_password2 = new JLabel("��ȷ���������룺     ");
	static JLabel label_blank = new JLabel("                 ");
	static JLabel label_error = new JLabel("�û���/���벻��Ϊ��,������ע�ᣡ");

	// �����ı������
	static JTextField tf_username = new JTextField(12);
	static JPasswordField tf_password = new JPasswordField(12);
	static JPasswordField tf_password2 = new JPasswordField(12);

	// ������ť����
	static JButton bt_confirm = new JButton("ȷ��");
	static JButton bt_quit = new JButton("ȡ��");

	public static void frame_register() {
		// ���ô���Ͳ�������Ļ�������
		f_register.setBounds(500, 200, 300, 150);
		f_register.setLayout(new FlowLayout());
		label_error.setFont(new Font("����", Font.BOLD, 16));

		// ������
		f_register.add(label_username);
		f_register.add(tf_username);
		f_register.add(label_password);
		f_register.add(tf_password);
		f_register.add(label_password2);
		f_register.add(tf_password2);

		f_register.add(bt_confirm);
		f_register.add(label_blank);
		f_register.add(bt_quit);

		f_register.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f_register.setUndecorated(false);// ȥ����������,������󻯰�ť
		f_register.setResizable(false); // ��ֹ�ı䴰���С

		// �����������̼�����ʹ�����ı������޷�����ո�':'��'|'
		tf_username.addKeyListener(new KeyAdapter() {
			@Override
			public void keyTyped(KeyEvent e) {
				char ch = e.getKeyChar();
				if (ch == KeyEvent.VK_SPACE || ch == ':' || ch == '|') { // ��������ǿո�':'��'|'ʱ
					e.consume(); // ȡ������¼����¼�
				}
			}
		});

		tf_password.addKeyListener(new KeyAdapter() {
			@Override
			public void keyTyped(KeyEvent e1) {
				char ch = e1.getKeyChar();
				if (ch == KeyEvent.VK_SPACE || ch == ':' || ch == '|') { // ��������ǿո�':'��'|'ʱ
					e1.consume();// ȡ������¼����¼�
				}
			}
		});

		tf_password2.addKeyListener(new KeyAdapter() {
			@Override
			public void keyTyped(KeyEvent e2) {
				char ch = e2.getKeyChar();
				if (ch == KeyEvent.VK_SPACE || ch == ':' || ch == '|') { // ��������ǿո�':'��'|'ʱ
					e2.consume(); // ȡ������¼����¼�
				}
			}
		});

		// ����"ȷ��"
		bt_confirm.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				// ��ȡ������û���������
				String username = tf_username.getText().trim();
				String password = tf_password.getText().trim();
				String password2 = tf_password2.getText().trim();

				// �û��������벻��Ϊ�գ����򵯳����󴰿�
				if (username.contentEquals("") || password.contentEquals("")) {
					JFrame f = new JFrame("ע�����");
					f.setBounds(500, 230, 300, 70);
					f.setLayout(new FlowLayout());
					f.add(label_error);
					f.addWindowListener(new WindowAdapter() {
						public void windowClosing(WindowEvent e) {
							// �ر�ȷ�Ͻ����ע�����
							f.dispose();
							f.setVisible(false);
							f_register.dispose();
							f_register.setVisible(false);
							// �Զ��򿪵�¼����
							Login.frame_login();
							Login.f_login.setVisible(true);
						}
					});
					f.setUndecorated(false);// ȥ����������,������󻯰�ť
					f.setResizable(false); // ��ֹ�ı䴰���С
					f.setVisible(true);
				}

				// ���������������һ�£������ע��
				else if (password.equals(password2)) {
					try {
						Account.register(username, password);
					} catch (IOException e1) {
						e1.printStackTrace();
						System.exit(1);
					}
				} else { // ��������������벻һ�£��򵯳����󴰿�
					JFrame f = new JFrame("ע�����");
					f.setBounds(500, 200, 300, 70);
					f.setLayout(new FlowLayout());
					JLabel label = new JLabel("ע�����,�����������벻һ�£�");
					f.add(label);
					label.setFont(new Font("����", Font.BOLD, 16));
					f.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
					f.setUndecorated(false);// ȥ����������,������󻯰�ť
					f.setResizable(false); // ��ֹ�ı䴰���С
					f.setVisible(true);
				}
				// confirmbool���ڱ���Ƿ�ע��ɹ���������ɹ����򲻲���
				if (confirmbool) {
					JFrame f = new JFrame("ע��ɹ�");
					JButton bt = new JButton("ȷ��");
					f.setBounds(0, 0, 200, 100);
					f.setLayout(null);
					JLabel label = new JLabel("ע��ɹ���");
					label.setBounds(50, 10, 100, 20);
					bt.setBounds(50, 40, 80, 20);
					bt.addMouseListener(new MouseAdapter() {
						@Override
						public void mouseClicked(MouseEvent e) {
							// �ر�ȷ�Ͻ����ע�����
							f.dispose();
							f.setVisible(false);
							f_register.dispose();
							f_register.setVisible(false);
						};
					});
					f.add(label);
					f.add(bt);
					label.setFont(new Font("����", Font.BOLD, 16));
					f.addWindowListener(new WindowAdapter() {
						public void windowClosing(WindowEvent e) {
							// �ر�ȷ�Ͻ����ע�����
							f.dispose();
							f.setVisible(false);
							f_register.dispose();
							f_register.setVisible(false);
							// �Զ��򿪵�¼����
							Login.frame_login();
							Login.f_login.setVisible(true);
						}
					});
					f.setUndecorated(false);// ȥ����������,������󻯰�ť
					f.setResizable(false); // ��ֹ�ı䴰���С
					f.setVisible(true);
					confirmbool = false;
				}
			}
		});

		// ����"ȡ��"
		bt_quit.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				System.exit(0);
			}
		});

	}
	
	/** 
	 * ����������Դ�ע��Ĵ���.
	 * <p>���ȼ���load()��������ȡ����ļ��е����ݣ������˻���Ϣ��Ȼ�����ô������ԣ����ʹ���ڿɼ�<br>
	 * @exception IOException On input error.
     * @see IOException
	 * @return û�з���ֵ
	 */
	public static void openRegisterFrame() throws IOException {
		 Account.load();
		 frame_register();
		 f_register.setVisible(true);
	}
	

}
