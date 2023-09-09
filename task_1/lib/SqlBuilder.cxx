#include "SqlBuilder.hxx"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(std::string _str) {
	(query.column == "*") ? query.column = _str : query.column += ", " + _str;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string _str) {
	query.from = _str;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::string _str1, std::string _str2) {
	(query.where == "") ? query.where = _str1 + "=" + _str2 : query.where += " AND " + _str1 + "=" + _str2;
	return *this;
}

void SqlSelectQueryBuilder::BuildQuery() {
	query.query = "SELECT " + query.column + " FROM " + query.from + " WHERE " + query.where + ";";
}