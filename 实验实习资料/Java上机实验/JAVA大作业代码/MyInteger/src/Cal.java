import java.util.Scanner;


public class Cal {


	public static void main(String[] args) {
		//����δ֪�������������������num[i]
		Scanner sc = new Scanner(System.in);
		//��ʼ������
		String[] nums=null;
		//ͨ���ո���벻ͬ���������������¡��ա���
		System.out.print("���������¡��ա���:");
		nums=sc.nextLine().split(" ");
		
		int num[]=new int[nums.length];
		//��ʼ����ͱ���sum
		int sum=0;
		
		for(int i=0;i<num.length;i++){
            num[i]=Integer.valueOf(nums[i]);
        }
		//���������ַ�ʱ����ܼ�
		if(num.length == 3)
		{
			int day = ((num[2]-1)+(num[2]-1)/4-(num[2]-1)/100+(num[2]-1)/400+1)%7; //������һ��ĵ�һ�����ܼ��Ĺ�ʽ�����Ϊday
			
			//36---62��¼����ͷ�������¼���������ÿ��if��ͨ��ѭ�����������·�ǰ�ѹ�������
			if(num[2]%100==0&&num[2]%400!=0) 
			{
				 int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
				 
				 for(int l=1;l<num[0];l++)
					{
						day = day + d[l-1];
					}
			}
			else if(num[2]%4!=0)
			{
				int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
				
				for(int l=1;l<num[0];l++)
				{
					day = day + d[l-1];
				}
			}
			else 
				{
					int d[] = {31,29,31,30,31,30,31,31,30,31,30,31};
					
					for(int l=1;l<num[0];l++)
					{
						day = day + d[l-1];
					}
				}
			//day�ټ���num[1]�����������ڸ������������1����ȥ��һ�죩��ģ7��Ϊ�ܼ�
			day=(day+num[1]-1)%7;
			//������
			switch (day) {
			case 1:System.out.println("Monday");break;
			case 2:System.out.println("Tuesday");break;
			case 3:System.out.println("Wednesday");break;
			case 4:System.out.println("Thursday");break;
			case 5:System.out.println("Friday");break;
			case 6:System.out.println("Saturday");break;
			case 0:System.out.println("Sunday");break;
			default:
				break;
			}
			
		}
		//������������ʱ�������
		else if(num.length == 2)
		{
			System.out.println("Su\tMo\tTu\tWe\tTh\tFr\tSa\t");
			
			int day = ((num[1]-1)+(num[1]-1)/4-(num[1]-1)/100+(num[1]-1)/400+1)%7;
			//���˼·����ͬ��������ʱ������������·�ǰ�ѹ�������day
			if(num[1]%100==0&&num[1]%400!=0) 
			{
				 int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
				 
				 for(int l=1;l<num[0];l++)
					{
						day = day + d[l-1];
					}
			}
			else if(num[1]%4!=0)
			{
				int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
				
				for(int l=1;l<num[0];l++)
				{
					day = day + d[l-1];
				}
			}
			else 
				{
					int d[] = {31,29,31,30,31,30,31,31,30,31,30,31};
					
					for(int l=1;l<num[0];l++)
					{
						day = day + d[l-1];
					}
				}
			//dayֱ��ģ7�ɵ������·ݵ�һ�����ܼ������Ϊday
			day = day%7;
			
			for(int m=0;m<day;m++)
			{
				System.out.print("\t"); //���ȿճ����µ�һ��֮ǰ��λ��
			}
			//�����������������+��λ�����ɣ�������ÿ�������Ľڵ㻻��
			if(num[1]%100==0&&num[1]%400!=0) 
			{
				 int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
					for(int n=1;n<=d[num[0]-1];n++)
					{
						System.out.print(n+"\t");
						day+=1;
						if(n!=1&&day%7==0)
						{
							System.out.print("\n");
						}
					}
			}
			else if(num[1]%4!=0)
			{
				int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
				for(int n=1;n<=d[num[0]-1];n++)
				{
					System.out.print(n+"\t");
					day+=1;
					if(n!=1&&day%7==0)
					{
						System.out.print("\n");
					}
				}
			}
			
			else 
				{
					int d[] = {31,29,31,30,31,30,31,31,30,31,30,31};
					for(int n=1;n<=d[num[0]-1];n++)
					{
						System.out.print(n+"\t");
						day+=1;
						if(n!=1&&day%7==0)
						{
							System.out.print("\n");
						}
					}
				}
			
		}
		
		}
		
	}
