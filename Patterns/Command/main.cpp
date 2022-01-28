/*
Паттерн Command преобразовывает запрос на выполнение действия в отдельный объект-команду.
Такая инкапсуляция позволяет передавать эти действия другим функциям и объектам в качестве параметра,
приказывая им выполнить запрошенную операцию. Команда – это объект, поэтому над ней допустимы любые операции, что и над объектом.

Интерфейс командного объекта определяется абстрактным базовым классом Command и в самом простом случае имеет
 единственный метод execute(). Производные классы определяют получателя запроса (указатель на объект-получатель)
и необходимую для выполнения операцию (метод этого объекта). Метод execute() подклассов Command просто вызывает нужную операцию получателя.
*/


#include <iostream>
#include<vector>
#include<string>

using namespace std;

class Game
{
  public:
    void create( ) {
      cout << "Create game " << endl;
    }
    void open( string file ) {
      cout << "Open game from " << file << endl;
    }
    void save( string file ) {
      cout << "Save game in " << file << endl;
    }
    void make_move( string move ) {
      cout << "Make move " << move << endl;
    }
};

string getPlayerInput( string prompt ) {
  string input;
  cout << prompt;
  cin >> input;
  return input;
}

// Базовый класс
class Command
{
  public:
    virtual ~Command() {}
    virtual void execute() = 0;
  protected:
    Command( Game* p ): pgame( p) {}
    Game * pgame;
};

class CreateGameCommand: public Command
{
  public:
    CreateGameCommand( Game * p ) : Command( p) {}
    void execute() {
      pgame->create( );
    }
};

class OpenGameCommand: public Command
{
  public:
    OpenGameCommand( Game * p ) : Command( p) {}
    void execute() {
      string file_name;
      file_name = getPlayerInput( "Enter file name:");
      pgame->open( file_name);
    }
};

class SaveGameCommand: public Command
{
  public:
    SaveGameCommand( Game * p ) : Command( p) {}
    void execute( ) {
      string file_name;
      file_name = getPlayerInput( "Enter file name:");
      pgame->save( file_name);
    }
};

class MakeMoveCommand: public Command
{
  public:
    MakeMoveCommand( Game * p) : Command( p) {}
    void execute() {
      // Сохраним игру для возможного последующего отката
      pgame->save( "TEMP_FILE");
      string move;
      move = getPlayerInput( "Enter your move:");
      pgame->make_move( move);
    }
};

class UndoCommand: public Command
{
  public:
    UndoCommand( Game * p ) : Command( p) {}
    void execute() {
      // Восстановим игру из временного файла
      pgame->open( "TEMP_FILE");
    }
};

int main(int argc, char *argv[])
{
    Game game;
    // Имитация действий игрока
    vector<Command*> v;
    // Создаем новую игру
    v.push_back( new CreateGameCommand( &game));
    // Делаем несколько ходов
    v.push_back( new MakeMoveCommand( &game));
    v.push_back( new MakeMoveCommand( &game));
    // Последний ход отменяем
    v.push_back( new UndoCommand( &game));
    // Сохраняем игру
    v.push_back( new SaveGameCommand( &game));

    for (size_t i=0; i<v.size(); ++i)
      v[i]->execute();

    for (size_t i=0; i<v.size(); ++i)
      delete v[i];

    return 0;
}