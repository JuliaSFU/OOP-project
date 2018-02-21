
#ifndef __ProgramOOP__
#define __ProgramOOP__

#include <fstream>
using namespace std;

namespace shapes {

	// �����, ����������� ��� ��������� ������. 
	class shape
	{
	private:
		enum color { RED, ORANGE, YELLOW, GREEN, BLUE, DARKBLUE, PURPLE };
	protected:
		color c;
		void InColor(int colorNumber);
		void OutColor(ofstream &ofst);
	public:
		shape() {};
		static shape* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0; //������ ����������� �������
		virtual void OutData(ofstream &ofst) = 0;
	};
	// �������������
	class rectangle : public shape
	{
	private:
		int x1, y1, x2, y2; // ������������� ���������� ������ �������� � ������� ������� �����

	public:
		void InData(ifstream &ifst); 
		void OutData(ofstream &ofst); 
		rectangle() {}; 
	};

	//����
	class circle : public shape
	{
	private:
		int a, b, r; // ������������� ���������� ������ ����������, ������
	public:
		void InData(ifstream &ifst); 
		void OutData(ofstream &ofst); 
		circle() {}; 
	};

	//��������� �� ������ ����������� ��������� ������
	class node
	{
	public:
		shape* data;
		node* next;
		node(shape* data, node* next);
	};

	class container
	{
	private:
		node* head;
	public:
		container() { head = NULL;  }
		void In(ifstream &ifst);
		void Out(ofstream &ofst);
		void Clear();
		~container() { Clear(); }
	};

}// end simple_shapes namespace
#endif