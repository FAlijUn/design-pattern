动作、事务、Action、Transaction、Command
命令模式是一种行为设计模式， 它可将请求转换为一个包含与请求相关的所有信息的独立对象
该转换让你能根据不同的请求将方法参数化、 延迟请求执行或将其放入队列中， 且能实现可撤销操作

应用场景
1. 命令模式是一种行为设计模式，它可将请求转换为一个包含与请求相关的所有信息的独立对象。该转换让你能根据不同的请求将方法参数化、延迟请求执行或将其放入队列中，且能实现可撤销操作。
2. 事务操作：在需要记录操作历史或支持撤销/重做功能的场景中，命令模式可以封装每个操作为一个命令对象，便于管理和恢复。
3. 事务操作：在需要记录操作历史或支持撤销/重做功能的场景中，命令模式可以封装每个操作为一个命令对象，便于管理和恢复。
4. GUI操作：图形用户界面中的按钮和菜单项可以看作是命令，用户的操作可以封装为命令对象，然后由界面触发执行。
5. 游戏操作：在游戏中，玩家的每个操作（如移动、攻击）都可以封装为命令对象，便于管理和撤销。
6. 日志记录：在需要记录用户操作日志的场景中，命令模式可以用于记录每个操作的详细信息，便于事后审计。
7. 网络请求：在网络编程中，可以将每个请求封装为命令对象，然后由服务器处理这些请求。
8. 命令队列：在需要异步处理命令的场景中，可以将命令对象放入队列中，由后台线程按顺序执行。