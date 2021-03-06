/*---------------------------------------------------------------
	* file:LinkQueue.c 
	* date:25-9-2014
	* author:doodlesomething@163.com
	* version:.1.0
	* description:链队的基本操作
----------------------------------------------------------------*/


#include <stdlib.h>
#include "linkqueue.h"


/*
* @description:初始化链队
*/
Status InitQueue(LinkQueue *Q) {
	(*Q).font = (QueuePtr) malloc(sizeof(QNode));

	if(!(*Q).font)
		exit(OVERFLOW);
	
	(*Q).rear = (*Q).font;

	(*Q).font->next = NULL;

	return OK;
}


/*
* @description:判空
*/
Status QueueEmpty(LinkQueue Q) {
	return Q.font == Q.rear;
}


/*
* @description:入队
*/
Status EnQueue(LinkQueue *Q,ElemType elem) {
	QueuePtr p;

	p = (QueuePtr) malloc(sizeof(QNode));

	if(!p)
		exit(OVERFLOW);
	
	p->data = elem;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;


	return OK;
}

/*
* @description:出队
*/
Status DeQueue(LinkQueue *Q,ElemType *elem) {
	if(QueueEmpty(*Q))
		return ERROR;
	
	QueuePtr p,tmp;

	p = (*Q).font;

	tmp = p->next;
	p->next = tmp->next;
	(*elem) = tmp->data;

	//注意当删除的是最后一个元素时，应该将队尾指针指向头结点
	if(tmp == (*Q).rear)
		(*Q).rear = (*Q).font;	

	free(tmp);

	return OK;
}


