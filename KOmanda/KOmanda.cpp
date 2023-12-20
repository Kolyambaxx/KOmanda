#include <iostream>


class Command {
public:
    virtual void execute() const = 0;
    virtual ~Command() = default;
};

class ConcreteCommand : public Command {
public:
    ConcreteCommand(const std::string& message) : message(message) {}

    void execute() const override {
        std::cout << "Concrete Command: " << message << std::endl;
    }

private:
    std::string message;
};


class Receiver {
public:
    void action() const {
        std::cout << "Receiver: Performing action" << std::endl;
    }
};


class Invoker {
public:
    void setCommand(const Command* command) {
        this->command = command;
    }

    void executeCommand() const {
        if (command) {
            command->execute();
        }
    }

private:
    const Command* command;
};


class ActionCommand : public Command {
public:
    ActionCommand(Receiver& receiver) : receiver(receiver) {}

    void execute() const override {
        receiver.action();
    }

private:
    Receiver& receiver;
};

int main() {
 
    Receiver receiver;


    ConcreteCommand command1("Command 1");
    ConcreteCommand command2("Command 2");

    Invoker invoker;
    invoker.setCommand(&command1);

   
    invoker.executeCommand();

   
    invoker.setCommand(&command2);
    invoker.executeCommand();

    
    const Command* actionCommand = new ActionCommand(receiver);
    invoker.setCommand(actionCommand);
    invoker.executeCommand();

    delete actionCommand;

    return 0;
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
