package user;

/** ��������ڼ�¼�û��������룬���ṩ��ע�ᡢ��¼�������û����ݵķ���.
 * @author �ι���
 * @version 1.0
 */

import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Label;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;

import javax.imageio.spi.RegisterableService;
import javax.swing.JFrame;
import javax.swing.JLabel;
import code.*;

public class Account {
	// �����û����������Ӧ��ӳ�伯�϶���
	static Map<String, String> accountMap = new HashMap<String, String>();
	
	// �����鼮�Ķ������������������Ϊ255��
	public static Book[] books = new Book[255];
	
	// confirmbool���ڱ���Ƿ�ע��ɹ�
	static boolean confirmbool = false;
	
	// ID��¼�ܱ����
	public static int ID = 0;

	/**
	 * �����������ע�����˻������Ѹ��˻�����Ϣ�Զ����浽��Ŀ¼��.
	 * @param username ע����û��������ܺ��пո�ΪString����
	 * @param password ע������룬���ܺ��пո�ΪString����
	 * @throws IOException
	 */
	public static void register(String username, String password) throws IOException {
		// �û���������Ϊ��ʱ���������󴰿�
		if (username == null || password == null || username.contentEquals("") || password.contentEquals("")) {
			JFrame f = new JFrame("ע�����");
			f.setBounds(500, 200, 300, 70);
			f.setLayout(new FlowLayout());
			JLabel label = new JLabel("ע�����,�û��������벻��Ϊ�գ�");
			f.add(label);
			label.setFont(new Font("����", Font.BOLD, 16));
			f.addWindowListener(new WindowAdapter() {
				public void windowClosing(WindowEvent e) {
					// �ر�ȷ�Ͻ���
					f.dispose();
					f.setVisible(false);
				}
			});
			f.setUndecorated(false);// ȥ����������,������󻯰�ť
			f.setResizable(false); // ��ֹ�ı䴰���С
			f.setVisible(true);
		}

		// �û��������벻Ϊ�գ������û����Ѵ���ʱ���������󴰿�
		else if (accountMap.containsKey(username)) {
			JFrame f = new JFrame("ע�����");
			f.setBounds(500, 220, 300, 70);
			f.setLayout(new FlowLayout());
			JLabel label = new JLabel("ע�����,���û����Ѵ��ڣ�");
			f.add(label);
			label.setFont(new Font("����", Font.BOLD, 16));
			f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			f.setUndecorated(false);// ȥ����������,������󻯰�ť
			f.setResizable(false); // ��ֹ�ı䴰���С
			f.setVisible(true);
		}

		// �û��������벻Ϊ�գ����û���δ����ʱ����������������ע��
		else {
			accountMap.put(username, password);
			// ������Ӧ�û���ר���ļ��У����ڴ洢��Ӧ������
			String direction = new String("accountList\\" + username);
			File folder = new File(direction);
			folder.mkdirs();
			
			// ����һ���ı��ļ�����¼�û���������
			File accountFile = new File("accountList\\" + username + "\\user.txt");
			accountFile.createNewFile();
			OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream(accountFile));
			osw.write("Username:" + username + "|" + "Password:" + password);
			osw.close(); // �ͷ���Դ
			
			//������һ���ı��ļ�����¼��Ŀ�������Լ����Ե���Ŀ
			File idFile = new File("accountList\\id.txt");
			idFile.createNewFile();
			BookDemo.recordID();

			// ָʾע��ɹ�
			confirmbool = true;
		}
	}

	/**
	 * ����������ڵ�¼�˻������ж��û����Ƿ���ڣ��Լ��û����������Ƿ�ƥ��.
	 * <p>��������ʱ����ΪLogin���д����˸����ʵ��жϹ��ܣ�������������������<br>
	 * @param username ��¼���û��������ܺ��пո�ΪString����
	 * @param password ��¼�����룬���ܺ��пո�ΪString����
	 * @return bool  true ��ʾ��½�ɹ���false��ʾ��¼ʧ��
	 * @throws IOException
	 */
	public static boolean login(String username, String password) {
		boolean bool = false;
		// ����û���������������ƥ�䣬�򷵻�true,����Ϊfalse
		if (accountMap.containsKey(username)) {
			if (password.contentEquals(accountMap.get(username))) {
				bool = true;
			}
		} else {
			bool = false;
		}
		// ���ؽ��
		return bool;

	}

	/**
	 * �����������ÿ����������ʱ�Զ����ظ�Ŀ¼�µ��˻�����.
	 * @throws IOException
	 */
	public static void load() throws IOException {
		File folder2 = new File("accountlist");
		File[] files = folder2.listFiles();
		if (files != null) {
			for (File f : files) {
				if (f.isDirectory()) {
					// �ַ�����ȡ��Ӧ��Ŀ¼�µ��û��˻���Ϣ
					InputStreamReader isr = new InputStreamReader(
							new FileInputStream("accountlist\\" + f.getName() + "\\user.txt"));
					int c_read = 0;
					String str_text = "";
					while ((c_read = isr.read()) != -1) {
						str_text += (char) c_read;
					}
					isr.close(); // �ͷ���Դ
					int start = str_text.indexOf(':') + 1;
					int end = str_text.indexOf('|');
					if (start >= 0 && end >= 0) {
						// �����û�����������ַ�����ʽ������������Ϊ��ֵ����ӵ�accountMap����
						String username = str_text.substring(start, end).trim();
						String password = str_text.substring(str_text.lastIndexOf(':') + 1).trim();
						accountMap.put(username, password);
					} else {
						System.out.println("Error!");
					}
				}
			}
		}
	}

}