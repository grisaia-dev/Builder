#include "SqlBuilder.hxx"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::vector<std::string>& columns) noexcept {
	query.column.clear();
	for (const auto& column : columns)
		query.column += column + ", ";
	query.column.erase(query.column.end()-2, query.column.end());
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string _str) {
	query.from = _str;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) noexcept {
	for (const auto& [key, value] : kv)
		query.where += key + "=" + value + " AND ";
	query.where.erase(query.where.end() - 5, query.where.end());
	return *this;
}

void SqlSelectQueryBuilder::BuildQuery() {
	query.query = "SELECT " + query.column + " FROM " + query.from + " WHERE " + query.where + ";";
}