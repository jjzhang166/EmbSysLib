//*******************************************************************
/*!
\file   Std/cList.cpp
\author Thomas Breuer
\date   31.01.2013, 22.03.2016
\brief  Sample
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
class cListItem_Example : public cList::Item
{
  public:
    //---------------------------------------------------------------
    cListItem_Example( cList *list = 0 )
    {
      if( list )
      {
        list->add( this );
      }
      cnt = 0;
    }

  private:
    //---------------------------------------------------------------
    virtual void update(void)
    {
      cnt++;
    }

  public:
    //---------------------------------------------------------------
    WORD cnt;

};

//*******************************************************************
cList list;

cListItem_Example  itemA( &list );
cListItem_Example  itemB;
cListItem_Example  itemC;

//*******************************************************************
int main(void)
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );

  while( 1 )
  {
    sys.run();

    list.updateAll();

    com.printf( "A=%3d, B=%3d C=%3d\r", itemA.cnt, 
                                        itemB.cnt, 
                                        itemC.cnt );

    if( itemA.cnt == 100 )
    {
      list.add( &itemB );
    }
    if( itemA.cnt == 1000 )
    {
      list.add( &itemC );
    }
  }
}
