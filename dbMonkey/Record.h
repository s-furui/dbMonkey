#include <db_cxx.h>
#include <msclr/marshal_cppstd.h>

namespace dbMonkey {
	using System::String;
	using msclr::interop::marshal_as;
	using std::string;

	public ref class Record {
	private:
		Dbc * _cursorp;
		const String^ _key;
		const String^ _data;

		String^ dbt2string(const Dbt &dbt) {
			return marshal_as<String^>(
				string(static_cast<char *>(dbt.get_data()), dbt.get_size()));
		}
	public:
		Record(Dbc *cursorp) {
			_cursorp = cursorp;
			Dbt key, data;
			cursorp->get(&key, &data, DB_CURRENT);
			_key = dbt2string(key);
			_data = dbt2string(data);
		}

		property const String^ Key {
			const String^ get() {
				return _key;
			}
		}

		property const String^ Data {
			const String^ get() {
				return _data;
			}
		}
	};
}
