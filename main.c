/*
 *����ƽ�����ȼ��㸴�ӣ�д�˳������ 
 *�����ª����Ϊ���ǳ�ѧ�ߣ����ǳ�������ʱ�䲻��
 *����λ���в�ϲ���磬���ָ��
 *��л��λʹ��
 *��ӭ��λ�Ľ� 
 */ 
#include <stdio.h>
#include<math.h> 
#define STANDARD_DEVIATION sqrt(variance(number))  //��׼��Ϊ����ƽ���� 
/*
*����Ϊ���к�������
*������;������ע��
*/ 
float average(float number[]);  //���ڼ���ƽ���� 
float weight_average(float number[],int weight[]);  //���ڼ����Ȩƽ���� 
float average_without_highest_and_lowest(float number[]);  //���ڼ���ȥ����ߺ���͵�ƽ��ֵ 
void sort(float number[],int left,int right);  //���ڶ��������� 
float median(float number[]);  //���ڼ�����λ�� 
float mode(float number[]);  //���ڼ���������ʵ��ûд�� 
float variance(float number[]);  //���ڼ��㷽�� 
float average_difference(float number[]);  //���ڼ���ƽ���� 
float range(float number[]);  //���ڼ��㼫�� 
int n;  //��¼���ݸ��� 
int main()
{
	int i;
	char b;
	for( ; ; )
	{
        printf("���������ݸ�����");
	    scanf("%d",&n);
	    float number[n];
	    printf("���������ݣ�");
	    //��ѭ���������� 
	    for(i=0;i<n; )
	    {
	    	scanf("%f",&number[i]);
	    	i++;
		}
		printf("�Ƿ��Ȩ(y/n)");
		scanf("%c",&b);  //��ȡ���з�����ֹ���� 
		scanf("%c",&b);
		if(b=='y'||b=='Y')
		{
			int weight[n];
			printf("������Ȩ��");
			for(i=0;i<n; )
			{
				scanf("%d",&weight[i]);
				i++;
			}
			printf("��Ȩƽ����Ϊ��%fp2\n",weight_average(number,weight));
		}
		printf("ƽ����Ϊ��%f\n",average(number));
		printf("��λ��Ϊ��%f\n",median(number));
		printf("����Ϊ��%f\n",variance(number));
		printf("��׼��Ϊ��%f\n",STANDARD_DEVIATION);
		printf("ƽ����Ϊ��%f\n",average_difference(number));
		printf("����Ϊ��%f\n",range(number));
		printf("�Ƿ����(y/n)");
		scanf("%c",&b);  //��ȡ���з�����ֹ���� 
		scanf("%c",&b);
		if(b=='y'||b=='Y')
		{
			continue;
		}
		else
		{
			break;
		}
    }
    return 0;
}
float average(float number[n])
{
	float sum;
	int i;
	//��ѭ�������ܺ� 
	for(i=0;i<n; )
	{
		sum += number[i];
		i++;
	}
	return sum/n;
}
float weight_average(float number[],int weight[])
{
	int i;
	float sum,sum2;
	//��ѭ������Ȩ֮�����ܺ� 
	for(i=0;i<n; )
	{
		sum += number[i]*weight[i];
		sum2 += weight[i];
		i++;
	}
	return sum/sum2;
}
void sort(float number[],int left,int right)
{
	/*
	 *����ʹ��˫·���� 
	 *ʹ�õݹ� 
	 */
    int i,j,temp;
    i=left;
    j=right;
    temp=number[left];
    if(left>right) return ;
    while(i!=j)
    {
        while(number[j]>=temp&&j>i)
            j--;
        if(j>i)
            number[i++]=number[j];
        while(number[i]<=temp&&j>i)
            i++;
        if(j>i)
            number[j--]=number[i];
    }
    number[i]=temp;
    sort(number,left,i-1);
    sort(number,i+1,right);
}
float median(float number[])
{
	sort(number,0,n-1); 
	return n%2==0?(number[n/2-1]+number[n/2])/2:number[n/2];  //
}
float average_without_highest_and_lowest(float number[])
{
	sort(number,0,n-1);
	int i;
	float sum;
	for(i=0;i<n-1;i++) //
	{
		sum += number[i];
	}
	return sum/(n-2);
}
float mode(float number[])
{
	//���ţ�ûд��������д�պ��� ����ӭ��λ�Ľ� 
	;
}
float variance(float number[])
{
	int i;
	float sum,average2 = average(number);
	for(i=0;i<n; )
	{
		sum += (number[i] - average2) * (number[i] - average2);
		i++;
	}
	return sum/n;
}
float average_difference(float number[])
{
	int i,j;
	float sum,average2=average(number);
	for(i=0;i<n; )
	{
		j=number[i]-average2;
		if(j<0)
		{
			sum += -j;
		}
		else
		{
			sum += j;
		}
		i++;
		j=0;
	}
	return sum/n;
}
float range(float number[])
{
	sort(number,0,n-1);
	return number[n-1]-number[0]; 
}
