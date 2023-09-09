#include <iostream>
#include "lib/SqlBuilder.hxx"

int main(void) {
	setlocale(LC_ALL, "ru");
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	query_builder.BuildQuery();

	if (query_builder.GetQuery() == "SELECT name, phone FROM students WHERE id=42 AND name=John;")
		std::cout << "Запрос построен верно!" << std::endl;
	else {
		std::cout << query_builder.GetQuery() << std::endl;
		std::cout << "Неверный запрос!" << std::endl;
	}

	return EXIT_SUCCESS;
}