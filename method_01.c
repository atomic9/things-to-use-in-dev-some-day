void MoveUnit()
{
   //We use the Raycast function of the Gameboard which will output in clickedCell which cell was clicked.
   if (Gameboard.Instance.Raycast(Camera.main.ScreenPointToRay(Input.mousePosition),
       out Vector3Int clickedCell))
   {
       //m_MovableCells contains all the cells our currently selected unit can move to.
       //So we check if the cell we just clicked is part of that list.
       if (m_MovableCells.Contains(clickedCell))
       {
           var unit = Gameboard.Instance.GetUnit(clickedCell);

           //only if there is no unit on the target cell do we move there
           if (unit == null)
           {
               MoveCommand cmd = new MoveCommand(m_SelectedUnit.CurrentCell, clickedCell);
               CommandManager.Instance.AddCommand(cmd);
           }
       }
   }

   DeselectUnit();
   m_CurrentState = State.SelectingUnit;
}
