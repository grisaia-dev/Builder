#pragma once
#include <string>

struct Query {
	std::string column;
	std::string from;
	std::string where;
	std::string query;
};

class SqlSelectQueryBuilder {
public:
	explicit SqlSelectQueryBuilder() { query.column = "*"; query.from = ""; query.where = ""; query.query = ""; }

	SqlSelectQueryBuilder& AddColumn(std::string _str);
	SqlSelectQueryBuilder& AddFrom(std::string _str);
	SqlSelectQueryBuilder& AddWhere(std::string _str1, std::string _str2);

	void BuildQuery();

	std::string GetQuery() { return query.query; }

private:
	Query query;
};