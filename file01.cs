class MoveCommand
{
   Transform moved;
 
   public MoveCommand(Transform target)
   {
       moved = target;
   }
 
   public void Execute()
   {
       moved.Translate(Vector3.back);
   }
}


//then where we detect input
if(Input.GetKeyDown(Keycode.S))
{
   MoveCommand command = new MoveCommand(transform);
   command.Execute();
}
