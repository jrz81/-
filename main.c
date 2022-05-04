/*
 *鉴于平均数等计算复杂，写此程序帮助 
 *程序简陋，因为我是初学者，还是初中生，时间不多
 *望各位大佬不喜勿喷，多多指导
 *感谢各位使用
 *欢迎各位改进 
 */ 
#include <stdio.h>
#include<math.h> 
#define STANDARD_DEVIATION sqrt(variance(number))  //标准差为方差平方根 
/*
*以下为所有函数声明
*函数用途见翼型注释
*/ 
float average(float number[]);  //用于计算平均数 
float weight_average(float number[],int weight[]);  //用于计算加权平均数 
float average_without_highest_and_lowest(float number[]);  //用于计算去掉最高和最低的平均值 
void sort(float number[],int left,int right);  //用于对数据排序 
float median(float number[]);  //用于计算中位数 
float mode(float number[]);  //用于计算众数（实际没写） 
float variance(float number[]);  //用于计算方差 
float average_difference(float number[]);  //用于计算平均差 
float range(float number[]);  //用于计算极差 
int n;  //记录数据个数 
int main()
{
	int i;
	char b;
	for( ; ; )
	{
        printf("请输入数据个数：");
	    scanf("%d",&n);
	    float number[n];
	    printf("请输入数据：");
	    //此循坏读入数据 
	    for(i=0;i<n; )
	    {
	    	scanf("%f",&number[i]);
	    	i++;
		}
		printf("是否加权(y/n)");
		scanf("%c",&b);  //读取换行符，防止出错 
		scanf("%c",&b);
		if(b=='y'||b=='Y')
		{
			int weight[n];
			printf("请输入权：");
			for(i=0;i<n; )
			{
				scanf("%d",&weight[i]);
				i++;
			}
			printf("加权平均数为：%fp2\n",weight_average(number,weight));
		}
		printf("平均数为：%f\n",average(number));
		printf("中位数为：%f\n",median(number));
		printf("方差为：%f\n",variance(number));
		printf("标准差为：%f\n",STANDARD_DEVIATION);
		printf("平均差为：%f\n",average_difference(number));
		printf("极差为：%f\n",range(number));
		printf("是否继续(y/n)");
		scanf("%c",&b);  //读取换行符，防止出错 
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
	//此循环计算总和 
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
	//此循环计算权之和与总和 
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
	 *排序使用双路快排 
	 *使用递归 
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
	//不才，没写出来，故写空函数 ，欢迎各位改进 
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
