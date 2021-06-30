#include"polynomial.h"

Polynomial readPoly()
{
	Polynomial p, rear, t;
	int c, e, n;
	scanf("%d", &n);
	p = (Polynomial)malloc(sizeof(struct PolyNode));
	p->link = NULL;
	rear = p;
	while (n--)
	{
		scanf("%d %d", &c, &e);
		attachPoly(c, e, &rear);
	}
	t = p;
	p = p->link;
	free(t);
	return p;
}

Polynomial multPoly(Polynomial p1, Polynomial p2)
{
	Polynomial t1, t2,p,rear,t;
	int c, e;
	t1 = p1;
	t2 = p2;
	p = (Polynomial)malloc(sizeof(struct PolyNode));
	p->link = NULL;
	rear = p;
	while (t2)
	{
		attachPoly(t1->coef*t2->coef, t1->expon + t2->expon, &rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1)
	{
		t2 = p2, rear = p;
		while (t2)
		{
			c=t1->coef*t2->coef;
			e = t1->expon + t2->expon;
			while (rear->link&&(rear->link->expon > e))
			{
				//�ҵ�����λ��
				rear = rear->link;
			}
			if (rear->link&&rear->link->expon == e)	//������ָͬ���Ľ��
			{
				if (rear->link->coef + c != 0)
					rear->link->coef += c;
				else
				{
					t = rear->link;
					rear->link = t->link;
					free(t);
				}
			}
			else
			{
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;
				t->link = rear->link;
				rear->link = t;
				rear = rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = p;
	p = p->link;
	free(t2);
	return p;

}

void printPoly(Polynomial p)
{
	int flag = 0;
	if (!p)
	{
		printf("0 0\n");
		return;
	}
	while (p)
	{
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d %d", p->coef, p->expon);
		p = p->link;
	}
	printf("\n");
}

Polynomial addPoly(Polynomial p1, Polynomial p2)
{
	Polynomial t1, t2,p,rear,t;
	t1 = p1;
	t2 = p2;
	p = (Polynomial)malloc(sizeof(struct PolyNode));
	p->link = NULL;
	rear = p;
	while (t1&&t2)
	{
		if (t1->expon == t2->expon)
		{
			if ((t1->coef) + (t2->coef) != 0)
				attachPoly((t1->coef) + (t2->coef), t1->expon, &rear);
			t1 = t1->link;
			t2 = t2->link;
		}
		else if (t1->expon > t2->expon)
		{
			attachPoly(t1->coef, t1->expon, &rear);
			t1 = t1->link;
		}
		else
		{
			attachPoly(t2->coef, t2->expon, &rear);
			t2 = t2->link;
		}
	}
	while (t1)
	{
		attachPoly(t1->coef, t1->expon, &rear);
		t1 = t1->link;
	}
	while (t2)
	{
		attachPoly(t2->coef, t2->expon, &rear);
		t2 = t2->link;
	}
	rear->link = NULL;
	t = p;
	p = p->link;
	free(t);
	return p;
}

void attachPoly(int c, int e, Polynomial *pRear)
{ /* �����ڱ���������Ҫ�ı䵱ǰ������ʽβ��ָ���ֵ�� */
/* ���Ժ������ݽ������ǽ��ָ��ĵ�ַ��*pRearָ��β��*/
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode)); /* �����½�� */
	P->coef = c; /* ���½�㸳ֵ */
	P->expon = e;
	P->link = NULL;
	/* ��Pָ����½����뵽��ǰ������ʽβ��ĺ��� */
	(*pRear)->link = P;
	*pRear = P; /* �޸�pRearֵ */
}