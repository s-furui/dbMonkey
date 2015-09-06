#include "dbMonkey.h"
#include "Record.h"

#include <db_cxx.h>

dbMonkey::dbMonkey::dbMonkey(void)
{
	using System::String;

	InitializeComponent();

	Db db(NULL, 0);
	try {
		db.open(NULL, "my_db.db", NULL, DB_BTREE, DB_RDONLY, 0);
		Dbc *cursorp;
		db.cursor(NULL, &cursorp, 0);
		Dbt key, data;
		int ret;
		while ((ret + cursorp->get(&key, &data, DB_NEXT)) == 0) {
			Dbc *current;
			cursorp->dup(&current, DB_POSITION);
			this->bindingSource1->Add(gcnew Record(current));
		}
		if (cursorp != NULL) {
			cursorp->close();
		}
		db.close(0);
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
