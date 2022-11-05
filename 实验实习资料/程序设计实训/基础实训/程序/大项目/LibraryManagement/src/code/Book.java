package code;

/** ������¼����Ϊһ����������һЩ�����ͷ���.
 * @author �ι���
 * @version 1.0
 */

public class Book {
	// ��ı��
	public int bID;
	// �������
	public String bName = new String();
	// �������
	public String bAuthor = new String();
	// δ�����ߵ������Ŀ
	public int bNumber1;
	// �ѱ����ߵ������Ŀ
	public int bNumber2;
	// ��ļ۸�
	public int bprice;
	
	public Book(){
		
	}
	
	public Book(String name, String author, int id, int num1, int num2, int price) {
		this.bName = name;
		this.bAuthor = author;
		this.bID = id;
		this.bNumber1 = num1;
		this.bNumber2 = num2;
		this.bprice = price;
	}

	// ��������
	public void setName(String name) {
		this.bName = name;
	}
	
	// ���ü۸�
	public void setPrice(int price) {
		this.bprice = price;
	}
	
	// �������
	public void setID(int ID) {
		this.bID = ID;
	}
	
	// ��������
	public void setAuthor(String author) {
		this.bAuthor = author;
	}
	
	// ������Ŀ
	public void setNumber(int number) {
		this.bNumber1 = number;
		this.bNumber2 = 0;
	}
	
	// ����
	public void borrowBook() {
		// ������д���
		if(bNumber1 > 0) {
			this.bNumber1 -= 1;
			this.bNumber2 += 1;
		} 
		// �����ǰû�д���
		else {
			System.out.println("��ǰ�鼮���޴��飡");
		}
	}
	
	// ����
	public void returnBook() {
		// ���������δ���黹
		if(bNumber2 > 0) {
			this.bNumber2 -= 1;
			this.bNumber1 += 1;
		} 
		// �������û���鱻����
		else {
			System.out.println("������δ���黹�ĸ��鼮��");
		}
	}
	
	// ���߲�ѯ�汾���ı�
	public String checkToString(Book b) {
		return ("�鼮���:" + b.bID + "|" + "�鼮����:" + b.bName + "|" + "����:" + b.bAuthor + "|" 
		+ "ʣ������:" + b.bNumber1 + "|"+ "�۸�:" + b.bprice + "|" + "δ�黹��Ŀ:" + b.bNumber2 + " \r\n");
	}
	
}
