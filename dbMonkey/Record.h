#include <db_cxx.h>
#include <msclr/marshal_cppstd.h>

namespace dbMonkey {
	using System::String;
	using msclr::interop::marshal_as;
	using std::string;

	public ref class Record {
	private:
		Dbc * _cursorp;
		String^ _key;
		String^ _data;
		bool _cached;

		String^ dbt2string(Dbt &dbt) {
			return marshal_as<String^>(
				string(static_cast<char *>(dbt.get_data()), dbt.get_size()));
		}

		void fetch() {
			Dbt key, data;
			_cursorp->get(&key, &data, DB_CURRENT);
			_key = dbt2string(key);
			_data = dbt2string(data);
			_cached = true;
		}
	public:
		Record(Dbc *cursorp) {
			_cursorp = cursorp;
			_cached = false;
		}

		property String^ Key {
			String^ get() {
				if (!_cached)
					fetch();
				return _key;
			}
		}

		property String^ Data {
			String^ get() {
				if (!_cached)
					fetch();
				return _data;
			}
		}
	};
}
