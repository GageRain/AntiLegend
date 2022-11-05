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

/** ����ഴ����¼���洰�ڣ���ʵ�ֵ�¼�ͽ���ע����湦��,ͬʱ��Ҳ�ǽ�������ĵ�һ������.
 * @author �ι���
 * @version 1.0
 */

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import user.Account;
import user.Register;

public class Login extends Account {

	// �����������
	final static JFrame f_login = new JFrame("����Ա��¼����");

	// ������ǩ����
	static JLabel label_username = new JLabel("�û�����");
	static JLabel label_password = new JLabel("���룺     ");
	static JLabel label_blank = new JLabel("         ");
	static JLabel label_blank2 = new JLabel("         ");
	static JLabel label_blank3 = new JLabel("         ");
	static JLabel label_error = new JLabel("�û���/���벻��Ϊ��,�����µ�¼��");

	// �����ı������
	static JTextField tf_username = new JTextField(18);
	static JPasswordField tf_password = new JPasswordField(18);

	// ������ť����
	static JButton bt_login = new JButton("��¼");

	static JButton bt_quit = new JButton("�˳�");

	// ��������������õ�¼�Ĵ���
	public static void frame_login() {
		// ���ô���Ͳ�������Ļ�������
		f_login.setBounds(500, 200, 300, 130);
		f_login.setLayout(new FlowLayout());
		label_error.setFont(new Font("����", Font.BOLD, 16));
		f_login.setResizable(false); // ��ֹ�ı䴰���С
		f_login.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);

		// ������
		f_login.add(label_username);
		f_login.add(tf_username);
		f_login.add(label_password);
		f_login.add(tf_password);

		f_login.add(bt_login);
		f_login.add(label_blank);

		f_login.add(label_blank2);
		f_login.add(bt_quit);

		// ���ü��̺����ļ����

		// ���ü��̼�����ʹ�����ı������޷�����ո�':'��'|'
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

		// ���������

		// ��������¼��
		bt_login.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				String username2 = tf_username.getText().trim();
				String password2 = tf_password.getText().trim();

				if (accountMap.containsKey(username2)) {
					if (password2.contentEquals(accountMap.get(username2))) {
						System.out.println("��½�ɹ���");
						f_login.dispose();
						f_login.setVisible(false);
						code.Menu.closeMainFrame();
						code.Menu.openManagerFrame();
					} else {
						JFrame f = new JFrame("��¼����");
						f.setBounds(500, 200, 250, 70);
						f.setLayout(new FlowLayout());
						JLabel label = new JLabel("��¼����,�û������������");
						f.add(label);
						label.setFont(new Font("����", Font.BOLD, 16));
						f.addWindowListener(new WindowAdapter() {
							@Override
							public void windowClosing(WindowEvent e) {
								f.setAlwaysOnTop(false);
								f.dispose();
								f.setVisible(false);
								f_login.setVisible(true);
							}
						});
						f.setUndecorated(false);// ȥ����������,������󻯰�ť
						f.setResizable(false); // ��ֹ�ı䴰���С
						f.setAlwaysOnTop(true);
						f_login.dispose();
						f_login.setVisible(false);
						f.setVisible(true);
					}
				} else {
					JFrame f = new JFrame("��¼����");
					f.setBounds(500, 200, 250, 70);
					f.setLayout(new FlowLayout());
					JLabel label = new JLabel("��¼����,�û������������");
					f.add(label);
					label.setFont(new Font("����", Font.BOLD, 16));
					f.addWindowListener(new WindowAdapter() {
						@Override
						public void windowClosing(WindowEvent e) {
							f.setAlwaysOnTop(false);
							f.dispose();
							f.setVisible(false);
							f_login.setVisible(true);
						}
					});
					f.setUndecorated(false);// ȥ����������,������󻯰�ť
					f.setResizable(false); // ��ֹ�ı䴰���С
					f.setAlwaysOnTop(true);
					f_login.dispose();
					f_login.setVisible(false);
					f.setVisible(true);
				}
			}
		});

		// ������ȡ����
		bt_quit.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				f_login.setVisible(false);
			}
		});

	}

	/**
	 * ����������Դ򿪵�¼�Ĵ���.
	 * <p>
	 * ���ȼ���load()��������ȡ����ļ��е����ݣ������˻���Ϣ��Ȼ�����ô������ԣ����ʹ���ڿɼ�<br>
	 * 
	 * @exception IOException On input error.
	 * @see IOException
	 * @return û�з���ֵ
	 */
	public static void openLoginFrame() throws IOException {
		Account.load();
		frame_login();
		f_login.setVisible(true);
	}

}
