package code;

/** �����ͼ��ݹ���ϵͳ�����������ڽ������ã����ߺ͹���Ա��
 * 
 * @author �ι���
 */

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.IOException;
import user.*;

import javax.swing.*;

public class Menu extends Account {
	// �����������
	static JFrame f_main = new JFrame("ͼ��ݹ���ϵͳ");
	static JFrame f_manage = new JFrame("ͼ��ݹ���ϵͳ-����Աģʽ");
	static JFrame f_checkAll = new JFrame("ȫ���鼮��Ϣ");
	static JFrame f_checkLent = new JFrame("�����鼮��Ϣ");

	// �����˵���
	static JMenuBar mb = new JMenuBar();

	// �����˵�
	static JMenu m_manager = new JMenu("����Ա");
	static JMenu m_help = new JMenu("����");

	// �����˵���
	static JMenuItem item_login = new JMenuItem("����Ա��¼");
	static JMenuItem item_register = new JMenuItem("����Աע��");

	// ������ǩ����
	static JLabel label_allbooks = new JLabel("��ǰȫ���鼮��Ϣ");
	static JLabel label_lentBooks = new JLabel("��δ�黹�鼮ͳ��");

	// ������ť����
	static JButton bt_borrow = new JButton("�����鼮"); // ���߽���
	static JButton bt_checkAll1 = new JButton("��ѯ�鼮");
	static JButton bt_checkBorrowed = new JButton("�ѽ��鼮");
	static JButton bt_return = new JButton("�黹�鼮");
	static JButton bt_quit1 = new JButton("�˳�ϵͳ");

	static JButton bt_checkAll2 = new JButton("��ѯȫ���鼮��Ϣ"); // ����Ա����
	static JButton bt_checkLent = new JButton("��ѯδ�黹�鼮");
	static JButton bt_addBook = new JButton("����鼮��Ϣ");
	static JButton bt_deleteBook = new JButton("ɾ���鼮��Ϣ");
	static JButton bt_quit2 = new JButton("�˳�����ϵͳ");

	/**
	 * ����������Դ��������ò���������.
	 */
	public static void openMainFrame() {
		// ���ô�������
		f_main.setBounds(0, 0, 800, 600);
		f_main.setLayout(new BorderLayout());

		// �����¼�
		
		// ����ͼ��
		bt_borrow.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				new BorrowBookMenu();
			}
		});
		
		// �黹ͼ��
		bt_return.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				new ReturnBookMenu();
			}
		});
		
		// ��ѯȫ���鼮
		bt_checkAll1.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				Process p = null;
				try {
					p = Runtime.getRuntime().exec("notepad.exe books//BookList.txt");
					Thread.sleep(6000); // ˯��6����
				} catch (IOException e1) {
					e1.printStackTrace();
				} catch (InterruptedException e1) {
					e1.printStackTrace();
				} finally {
					p.destroy(); // ���ٽ���
				}
			}
		});
		
		// ��ѯδ�黹�鼮
		bt_checkBorrowed.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				try {
					new CheckLentMenu();
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
		
		// ����Ա��¼
		item_login.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				try {
					Login.openLoginFrame();
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});

		// ����Աע��
		item_register.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				try {
					user.Register.openRegisterFrame(); // ��ע�����
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});

		// �رհ�ť
		bt_quit1.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				System.exit(0);
			}
		});

		// f_main����������
		// ��Ӳ˵���
		m_manager.add(item_login);
		m_manager.add(item_register);
		mb.add(m_manager);
		mb.add(m_help);
		f_main.setJMenuBar(mb);
		// ��Ӱ�ť
		f_main.add(bt_borrow, BorderLayout.WEST);
		f_main.add(bt_checkAll1, BorderLayout.CENTER);
		f_main.add(bt_return, BorderLayout.EAST);
		f_main.add(bt_quit1, BorderLayout.SOUTH);
		f_main.add(bt_checkBorrowed, BorderLayout.NORTH);
		// ���������ڿɹرա��ɼ�
		f_main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f_main.setVisible(true);
	}

	/**
	 * ����������Թر�������
	 */
	public static void closeMainFrame() {
		f_main.dispose();
		f_main.setVisible(false);
	}

	/**
	 * ����������Դ��������ò��򿪹���Ա����.
	 */
	public static void openManagerFrame() {
		f_manage.setBounds(0, 0, 800, 600);
		f_manage.setLayout(new BorderLayout());

		// �����¼�
		// ����鼮
		bt_addBook.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				new AddBookMenu();
			}
		});
		
		// ɾ���鼮
		bt_deleteBook.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				new DeleteBookMenu();
			}
		});
		
		// ��ѯȫ���鼮
		bt_checkAll2.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				Process p = null;
				try {
					p = Runtime.getRuntime().exec("notepad.exe books//BookList.txt");
					Thread.sleep(6000); // ˯��������
				} catch (IOException e1) {
					e1.printStackTrace();
				} catch (InterruptedException e1) {
					e1.printStackTrace();
				} finally {
					p.destroy(); // ���ٽ���
				}
			}
		});
		
		// ��ѯδ�黹�鼮
		bt_checkLent.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				try {
					new CheckLentMenu();
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
		
		// �رհ�ť
		bt_quit2.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				f_manage.dispose();
				f_manage.setVisible(false);
				openMainFrame();
			}
		});

		// ��Ӱ�ť
		f_manage.add(bt_addBook, BorderLayout.WEST);
		f_manage.add(bt_checkAll2, BorderLayout.CENTER);
		f_manage.add(bt_deleteBook, BorderLayout.EAST);
		f_manage.add(bt_checkLent, BorderLayout.NORTH);
		f_manage.add(bt_quit2, BorderLayout.SOUTH);

		// ���������ڿɼ�
		f_manage.setVisible(true);
	}

}
