#pragma once
#include <string>
#include <vector>
#include <map>

struct Query {
	std::string column;
	std::string from;
	std::string where;
	std::string query;
};

class SqlSelectQueryBuilder {
public:
	explicit SqlSelectQueryBuilder() { query.column = "*"; query.from = ""; query.where = ""; query.query = ""; }

	SqlSelectQueryBuilder& AddColumn(const std::vector<std::string>& columns) noexcept;
	SqlSelectQueryBuilder& AddFrom(std::string _str);
	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;

	void BuildQuery();

	std::string GetQuery() { return query.query; }

private:
	Query query;
};