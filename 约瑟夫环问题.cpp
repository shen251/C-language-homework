#include<stdio.h>
#include <stdlib.h>
typedef struct node{
	int num;
	struct node *next;
}node;
int main(){
	int n,k,m,q=0;
	printf("请输入人数,起始编号,计数\n");
	scanf("%d%d%d",&n,&k,&m);
	node *hend,*p,*temp;   //*hend  头地址  *p动态地址  *temp 临时地址 
	hend=(node*)malloc(sizeof(node));//malloc 向系统申请内存 sizeof  计算node占用的字节数  node*转换为node形式的地址
	hend->num=1; //等价于(*hend).num 先解指针再赋值 
	p=hend;
	for(int i=2;i<=n;i++){
		temp=(node*)malloc(sizeof(node));
		temp->num=i;   
		p->next=temp;   //p->next可以等价于(*p).next 
		p=temp;
	} 
	p->next=hend;  //将最后一个与第一个链接 
	p=hend;    // 
	while(p->next->num != k){
        p = p->next;        //找到第K个人的前一个人 这样在往后数 计数  的时候直接往后数 
                            //如果这一步直接数到K 往后无法后退  因为链表 只能前进 
    }
	while(n!=1){
		int x,y;
		x=m/n;
		y=m%n; 
		if(y!=0){
		    q=m-n*x;
		}
		else{
			q=n;   //处理m大于n的情况 
		}					
	    for(int i=1;i<q;i++){
	    	p=p->next;    //数到第m个数的前一个 
		}
		node *per;
		per=p->next;
		p->next=per->next;
		printf("踢出局的编号为%d\n",per->num);
		free(per);    //释放内存 
	    n=n-1;
	}
	printf("获胜者为%d\n",p->num);
	free(p);
	return 0;	
}
