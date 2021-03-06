#pragma once

class BookHandler
{
public:
	static BookHandler& GetSingleton()
	{
		static BookHandler instance;
		return instance;
	}

	void Initialize()
	{
		SkillBooks.clear();

		auto dataHandler = RE::TESDataHandler::GetSingleton();
		auto books = dataHandler->GetFormArray<RE::TESObjectBOOK>();

		for (auto book : books)
		{
			if (book->TeachesSkill())
			{
				SkillBooks[book] = book->GetSkill();
			}
		}
	}

	std::map<RE::TESObjectBOOK*, RE::ActorValue> SkillBooks;

private:
	BookHandler() = default;
	~BookHandler() = default;
	BookHandler(const BookHandler& other) = delete;
	BookHandler(BookHandler&& other) = delete;
	BookHandler& operator=(const BookHandler& other) = delete;
	BookHandler& operator=(BookHandler&& other) = delete;
};
