#include "stdafx.h"
#include <fstream>
#include "Program.h"

using namespace std;

namespace shapes {


	// ���� ���������� ���������� ������ �� �����
	shape* shape::In(ifstream &ifst)
	{
		shape *sp;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			sp = new rectangle;
			break;
		case 2:
			sp = new circle;
			break;
		default:
			return 0;
		}
		sp->InData(ifst);
		return sp;
	}
	
	node::node(shape* data, node* next)
	{
		this->data = data;
		this->next = next;
	}

	// ������� ���������� �� ���������
	// (������������ ������)
	void container::Clear()
	{
		while (head != NULL)
		{
			node* forDelete = head;
			head = head->next;
			delete forDelete;
		}
	}
	// ���� ����������� ���������� �� ���������� ������
	void container::In(ifstream &ifst)
	{
		while (!ifst.eof()) {
			node* last = NULL;
			node* temp = new node(shape::In(ifst), NULL);
			if (head == NULL)
				head = temp;
			else {
				last = head;
				while (last->next != NULL) last = last->next;
				last->next = temp;
			}
		}
	}

	// ����� ����������� ���������� � ��������� �����
	void container::Out(ofstream &ofst)
	{
		ofst << "Container contains elements:" << endl;
		node* current = head;
		if (current == NULL)
			return;
		while (current != NULL)
		{
			current->data->OutData(ofst);
			current = current->next;
		}
	}

	//���� �����
	void shape::InColor(int colorNumber)
	{
		switch (colorNumber)
		{
		case 1:
			c = shape::color::RED;
			break;
		case 2:
			c = shape::color::ORANGE;
			break;
		case 3:
			c = shape::color::YELLOW;
			break;
		case 4:
			c = shape::color::GREEN;
			break;
		case 5:
			c = shape::color::BLUE;
			break;
		case 6:
			c = shape::color::PURPLE;
			break;
		}
	}

	//����� �����
	void shape::OutColor(ofstream &ofst)
	{
		switch (c)
		{
		case shape::color::RED:
			ofst << "RED" << endl;
			break;
		case shape::color::ORANGE:
			ofst << "ORANGE" << endl;
			break;
		case shape::color::YELLOW:
			ofst << "YELLOW" << endl;
			break;
		case shape::color::GREEN:
			ofst << "GREEN" << endl;
			break;
		case shape::color::BLUE:
			ofst << "BLUE" << endl;
			break;
		case shape::color::PURPLE:
			ofst << "PURPLE" << endl;
			break;
		}
	}


	// ���� ���������� �������������� �� �����
	void rectangle::InData(ifstream &ifst)
	{
		int c;
		ifst >> x1 >> y1 >> x2 >> y2 >> c;
		InColor(c);
	}
	// ����� ���������� �������������� � �����
	void rectangle::OutData(ofstream &ofst)
	{
		ofst << "It is Rectangle: x1 = " << x1
			<< ", y1 = " << y1
			<< ", x2 = " << x2
			<< ", y2 = " << y2 << ", color: ";
			OutColor(ofst);
	}


	// ���� ���������� ����� �� ������
	void circle::InData(ifstream &ifst)
	{
		int c;
		ifst >> a >> b >> r >> c;
		InColor(c);
	}
	// ����� ���������� ����� � ����
	void circle::OutData(ofstream &ofst)
	{
		ofst << "It is Circle: a = "
			<< a << ", b = " << b
			<< ", r = " << r << ", color: ";
		OutColor(ofst);
	}


} // end simple_shapes namespace