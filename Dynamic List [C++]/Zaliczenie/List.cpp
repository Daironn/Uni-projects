#include "pch.h"
#include "List.h"

void List::push_back(int i)
{
	Object * node = new Object;
	node->data = i;
	node->next = nullptr;

	if (this->is_empty()) {

		this->first = node;
		this->last = node;
	}
	else {
		this->last->next = node;
	}
	this->last = node;
	list_size++;
}

void List::push_front(int i)
{
	Object * node = new Object;
	node->data = i;

	if (this->is_empty()) {

		this->first = node;
		this->last = node;
	}
	else {
		node->next = this->first;
	}
	this->first = node;
	list_size++;
}

void List::pop_back()
{
	if (!this->is_empty()) {

		if (this->list_size != 1) {
			Object * node = new Object;
			node = this->first;

			delete (this->last);

			for (int i = 0; i < this->list_size - 2; i++) {

				node = node->next; // dodac ifa co sprawdza czy size = 1
			}
			this->last = node;
			list_size--;
		}
		else
			this->pop_front();
	}
	else
		std::cout << "Your list is empty";
}

void List::pop_front()
{
	if (!this->is_empty()) {

		Object * node = new Object;

		node = this->first->next;

		delete(this->first); 
		this->first = node;
		list_size--;
	}
	else
		std::cout << "Your list is empty";
}

void List::pop_value(int value)
{

	if (this->is_empty()) {

		std::cout << "Pusta\n";
	}
	else {

		Object * curr = new Object;
		curr = this->first;

		Object * prev = new Object;


		for (int i = 0; i < this->list_size; i++) {

			if (curr->data == value) {
				break;
			}
			else {

				prev = curr;
				curr = curr->next;
			}
		}
		if (this->first == curr) {
			this->pop_front();
		}
		else if (this->last = curr) {
			this->pop_back();
		}
		else {

			prev->next = curr->next;
			delete curr;
			this->list_size--;
		}
	}
}

void List::read(const std::string & filename)
{

	std::fstream plik;
	plik.open(filename, std::ios::in);

	if (plik.good() == true)
	{
		std::string line;
		std::string word;

		getline(plik, line);

		for (int i = 0; i < line.size(); i++) {
			if (line[i] != ' ') {
				word += line[i];
			}
			else {
				int e = strtol(word.c_str(),NULL,10);
				this->push_back(e);
				word = "";
			}
		}
		plik.close();
	}
}

void List::write(const std::string & filename)
{

	Object * node = new Object;
	node = this->first;

	std::fstream plik;
	plik.open(filename, std::ios::out);

	if (plik.good() == true)
	{

		for (int i = 0; i < this->list_size; i++) {

			plik << node->data << " ";
			node = node->next;
		}
		plik.close();
	}
}

void List::show() const
{
	if (!this->is_empty()) {

		Object * node = new Object;
		node = this->first;

		for (int i = 0; i < this->list_size; i++) {

			std::cout << node->data << " ";
			node = node->next;
		}
	}
	else
		std::cout << "List is empty" << std::endl;

}

void List::sort()
{

	for (int i = 0; i < this->list_size; i++) {

		Object * node = new Object;
		node = this->first;

		for (int j = 0; j < this->list_size-1; j++) {

			if (node->data > node->next->data) {

				this->swap(node, node->next);
			}
			node = node->next;

		}
	}
}

void List::swap(Object * ob1, Object * ob2)
{
	
	int a = ob1->data;
	ob1->data = ob2->data;
	ob2->data = a;


}

bool List::is_empty() const
{
	if (list_size == 0)
		return true;
	else
		return false;
}