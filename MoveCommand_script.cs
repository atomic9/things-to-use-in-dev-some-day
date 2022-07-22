public void Undo()
{
   var unit = Gameboard.Instance.GetUnit(m_To);
   if (unit != null)
   {
       Gameboard.Instance.MoveUnit(unit, m_From);
   }

    //we switch back which team is playing, as we undid a move, it go back to previous team
    Gameboard.Instance.SwitchTeam();
}
