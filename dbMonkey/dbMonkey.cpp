#include "dbMonkey.h"
#include "Record.h"
#include <db_cxx.h>

dbMonkey::dbMonkey::dbMonkey(void)
{
	using System::String;

	InitializeComponent();

	db = new Db(NULL, 0);
	try {
		db->open(NULL, "my_db.db", NULL, DB_BTREE, DB_RDONLY, 0);
		pin_ptr<Dbc*> p = &cursorp;
		db->cursor(NULL, p, 0);
		p = nullptr;
		Dbt key, data;
		int ret;
		while ((ret = cursorp->get(&key, &data, DB_NEXT)) == 0) {
			Dbc *current;
			cursorp->dup(&current, DB_POSITION);
			this->bindingSource1->Add(gcnew Record(current));
		}
	}
	catch (DbException &e) {
		std::cerr << e.what() << std::endl;
		throw e;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		throw e;
	}
}

dbMonkey::dbMonkey::~dbMonkey()
{
	if (components)
	{
		delete components;
	}
	try {
		if (cursorp != NULL)
			cursorp->close();
		db->close(0);
	}
	catch (DbException &e) {
		std::cerr << e.what() << std::endl;
		throw e;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		throw e;
	}
}
