package code;

import java.io.File;

/** ��������������ͼ����ص�һϵ�й��ܺͷ���
 * 
 * @author �ι���
 */

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import user.Account;

public class BookDemo extends Account {

	// ���ͼ�飨����������ļ�������ID�ţ�������ļ�������BookMenu��
	public static void addBook() throws IOException {
		uploadID();
		Account.ID += 1;
		recordID();
		String direction = new String("books//" + ID + ".txt");
		File folder = new File("books");
		File book = new File(direction);
		folder.mkdir();
		book.createNewFile();
	}

	// ɾ��ͼ�飨������ɾ���ļ�������Ĵ��ڼ�BookMenu��
	public static int deleteBook(int id) throws IOException {
		uploadID();
		int flag_delete = 0; // ���ñ��
		// ����·��
		File folder = new File("books");
		File[] books = folder.listFiles();
		// ɾ��·����ָ����ŵ��鼮
		for (File f : books) {
			// ����з��ϵ��ļ�����ɾ��
			if (f.getName().contentEquals(id + ".txt")) {
				f.delete();
				uploadBooks();
				return 1;
			}
		}
		if (flag_delete == 0) {
			new NoteMenu("ɾ��ʧ��", "�ñ�ŵ��鼮�����ڣ�");
		}
		return 0;
	}

	// ���ݱ�Ž���ͼ��
	public static int borrowBook(int idNum) throws IOException {
		uploadBooks();
		if (books[idNum] != null) {
			int num1 = books[idNum].bNumber1;
			int flag = 1;
			if (num1 >= 1 && flag == 1) {
				books[idNum].bNumber1 -= 1;
				books[idNum].bNumber2 += 1;
				recordBook(books[idNum]);
				flag -= 1;
				return 1;
			}
		}
		return 0;
	}

	// ���ݱ�Ź黹ͼ��
	public static int returnBook(int idNum) throws IOException {
		uploadBooks();
		if (books[idNum] != null) {
			int num2 = books[idNum].bNumber2;
			int flag = 1;
			if (num2 >= 1 && flag == 1) {
				books[idNum].bNumber2 -= 1;
				books[idNum].bNumber1 += 1;
				recordBook(books[idNum]);
				flag -= 1;
				return 1;
			}
		}
		return 0;
	}

	// ��¼ͼ�������ļ���
	public static void recordID() throws IOException {
		OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream("accountList\\id.txt"));
		String str = "" + Account.ID;
		osw.write(str);
		osw.close();
	}

	// ��ȡ�ļ��е�ͼ����
	public static void uploadID() throws IOException {
		InputStreamReader isr = new InputStreamReader(new FileInputStream("accountlist\\id.txt"));
		int c_read = 0;
		String str_text = "";
		while ((c_read = isr.read()) != -1) {
			str_text += (char) c_read;
		}
		isr.close(); // �ͷ���Դ

		int id_read = Integer.parseInt(str_text);
		ID = id_read;

	}

	// ��¼�����Book b���ļ���Ϣ
	public static void recordBook(Book b) throws IOException {
		File book = new File("books//" + b.bID + ".txt");
		OutputStreamWriter osw1 = null;
		if (book.exists()) {
			try {
				osw1 = new OutputStreamWriter(new FileOutputStream(book));
				osw1.write(b.checkToString(b));
				osw1.close();
			} catch (FileNotFoundException e1) {
				e1.printStackTrace();
			} catch (IOException e1) {
				e1.printStackTrace();
			}

			// �޸�BookListc����
			uploadBooks();
		}
	}

	// *��ȡ�ļ��е�ͼ��,�����ļ���ʽ�洢��BookList��
	public static void uploadBooks() throws IOException {
		String list = new String(); // ���ڴ洢�����鼮��Ϣ
		// ����·��
		File booklist = new File("books//BookList.txt");
		File folder = new File("books");
		if (booklist.exists()) {
			booklist.delete();
			booklist.createNewFile();
		} else {
			booklist.createNewFile();
		}
		File[] books = folder.listFiles();
		// ��ȡ·�������е��鼮
		for (File f : books) {
			String str = f.getName();
			// ��str_text��ȡ�ļ�����
			InputStreamReader isr = new InputStreamReader(new FileInputStream("books\\" + f.getName()));
			int c_read = 0;
			String str_text = "";
			while ((c_read = isr.read()) != -1) {
				str_text += (char) c_read;
			}
			isr.close(); // �ͷ���Դ
			// ��ȡ���ı���Book�������ʽ�洢
			if (!(str.contentEquals("BookList.txt"))) {
				// ��¼���
				int index = str.indexOf('.');
				int id = Integer.parseInt(str.substring(0, index));

				int fir1 = str_text.indexOf(':', 0) + 1;
				int fir2 = str_text.indexOf('|', 0);

				// ��¼����
				int index1 = str_text.indexOf(':', fir1) + 1;
				int index2 = str_text.indexOf('|', fir2 + 1);
				String name = str_text.substring(index1, index2);

				// ��¼����
				int index3 = str_text.indexOf(':', index1) + 1;
				int index4 = str_text.indexOf('|', index2 + 1);
				String author = str_text.substring(index3, index4);

				// ��¼ʣ������
				int index5 = str_text.indexOf(':', index3) + 1;
				int index6 = str_text.indexOf('|', index4 + 1);
				int num1 = Integer.parseInt(str_text.substring(index5, index6));

				// ��¼�۸�
				int index7 = str_text.indexOf(':', index5) + 1;
				int index8 = str_text.indexOf('|', index6 + 1);
				int price = Integer.parseInt(str_text.substring(index7, index8));

				// ��¼δ������
				int index9 = str_text.indexOf(':', index7) + 1;
				int indexX = str_text.indexOf(' ', index6 + 1);
				int num2 = Integer.parseInt(str_text.substring(index9, indexX).trim());
				Book b = new Book(name, author, id, num1, num2, price);
				Account.books[id] = b;

				// ��ȫ���鼮��Ϣ��������һ���ļ�
				OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream(booklist, true));
				osw.write(b.checkToString(b));
				osw.close();
			}
		}
	}
}
