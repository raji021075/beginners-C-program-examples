#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void quicksort(int [], int , int );
int operations()
{
  int option;
  printf("\n\n");
  printf("Choose any one option given below \n");
  printf("1. Add a new item \n");
  printf("2. Update the price of an item \n");
  printf("3. Update the stock \n");
  printf("4. Show the price list \n");
  printf("5. Sell an item \n");
  printf("6. Sort the records\n");
  printf("7. Print \n");
  printf("8. Exit \n");
  printf("\n");
  
  printf("Enter your option:");
  scanf("%d", &option);

  return (option);
}

  struct Item
  {
    char itemName[20];
    int itemCode;
    float price;
    int QtyInStock;
  };
int main()
{
/*  struct Item
  {
    char itemName[20];
    int itemCode;
    float price;
    int QtyInStock;
  };*/

  struct Item    req[5];
  int option, item = 0, code = 0, i = 0, j = 0, sell = 0, found = 0;
  char temp [100];

  option = operations();
  while (option != 8)
  {
    switch(option)
    {
       case 1:
       {
          
          printf("We are adding a new item to the list \n");
	  printf("Enter name of the item: ");
	  scanf("%s", req[item].itemName);
	  printf("Enter item code: ");
	  scanf("%d", &req[item].itemCode);
	  printf("Enter price of one item: ");
	  scanf("%f", &req[item].price);
	  printf("Enter number of items in stock: ");
	  scanf("%d", &req[item].QtyInStock);
	  printf("\n");
	  printf("\n");
	  printf("Details of items added: \n");
	  printf("Name of the item   :%s \n", req[item].itemName);
	  printf("Item code          :%d \n", req[item].itemCode);
	  printf("Price of the item  :%.1f rupees \n", req[item].price);
	  printf("Stock present      :%d \n", req[item].QtyInStock);
          item++;
	  break;
       }
       case 2:
       {
          if (item == 0)
          {
             printf("No items present \n");
	     break;  
	  }
	  printf("Enter the item code that you want to change price \n");
	  scanf("%d", &code);


	  for(i = 0; i < item; i++)
          {
	     if(code == req[i].itemCode)
             {
	        printf("Enter new price of item \n");
		scanf("%f", &req[i].price);
		printf("Details of the updated item \n");
		printf("Name of the item   :%s \n", req[i].itemName);
                printf("Item code          :%d \n", req[i].itemCode);
                printf("Price of the item  :%.1f rupees \n", req[i].price);
                printf("Stock present      :%d \n", req[i].QtyInStock);
		printf("\n");
		printf("\n");
		found = 1;
		break;
	     }
	  }
	  if (found == 0)
          {
	   printf("No item found \n");
	   break;
	  }
	  break;
       }
       case 3:
       {
         if (item == 0)
          {
             printf("No items present \n");
	     break;  
	  }
	  printf("Enter the item code that you want to change stock \n");
	  scanf("%d", &code);

	  for(i = 0; i < item; i++)
          {
	     if(code == req[i].itemCode)
             {
	        printf("Enter new stock of item \n");
		scanf("%d", &req[i].QtyInStock);
		printf("Details of the updated item \n");
		printf("Name of the item  %s \n", req[i].itemName);
                printf("Item code         %d \n", req[i].itemCode);
                printf("Price of the item %.1f rupees \n", req[i].price);
                printf("Stock present     %d \n", req[i].QtyInStock);
		printf("\n");
		printf("\n");
		found = 1;
		break;
	     }
	  }
	  if (found == 0)
          {
	    printf("No item found \n");
	    break;
	  }
	  break;
       }
       case 4:
       {
          if (item == 0)
          {
             printf("No items present \n");
	     break;  
	  }
	  printf("Price list of all the items present \n");
	  for (i = 0; i < item; i++ )
          {
	     printf("Item name   %s\nItem code   %d\nItem cost   %.1f\nStock available %d\n", req[i].itemName, req[i].itemCode, req[i].price, req[i].QtyInStock);
	  } 
	  break;
       }
       case 5:
       {
         if (item == 0)
         {
            printf("No items present \n");
            break;  
         }
	 printf("Enter the item code that you want to sell \n");
	 scanf("%d", &code);
	 for (i = 0; i < item; i++)
         {
           if(code == req[i].itemCode)
           {
	     printf("Enter quantity to buy: ");
	     scanf("%d", &sell);
	     if(sell > req[i].QtyInStock)
             {
	        printf("Enough quantity not available. Maximum quantity is %d\n", req[i].QtyInStock);
	        found = 1;
		break;
	     }
	     req[i].QtyInStock = req[i].QtyInStock - sell;
	     printf("Details of the sold item: \n");
             printf("Name of the item  %s \n", req[i].itemName);
             printf("Item code         %d \n", req[i].itemCode);
             printf("Price of the item %.1f rupees \n", req[i].price);
             printf("Stock present     %d \n", req[i].QtyInStock);
             printf("\n");
             printf("\n");
	     found = 1;
	     break;
	   }
	 }
	 if(found == 0)
         {
	   printf("No item found \n");
	   break;
	 }
       }
       break;
       case 6:
       {
          if (item == 0)
          {
             printf("No items present \n");
	     break;
	  }
          quicksort(req->itemCode, 0, item);

       break;
       case 7:
       {
          if (item == 0)
          {
             printf("No items present \n");
	     break;  
	  }
	  printf("Price list of all the items present \n");
	  for (i = 0; i < item; i++ )
          {
	     printf("Item name   %s\nItem code   %d\nItem cost   %.1f\nStock available %d\n", req[i].itemName, req[i].itemCode, req[i].price, req[i].QtyInStock);
	  } 
	  break;
        }
        break;
    }

/*    default:
    {
      printf("Enter valid option \n");
      break;
    }
*/

    found = 0;
    option = operations();
  }

  exit(0);

}

void quicksort(int req[]->itemCode, int first, int last){
    int i, j, pivot, temp, temp1;

    if(first < last){
      pivot = first;
      i = first;
      j = last;

      while (i < j){
        while (req[i].itemCode <= req[pivot].itemCode && i < last)
           i++;
        while (req[i].itemCode > req[pivot])
	   j++;
        if(i < j){
               strcpy(temp, req[i].itemName);
               strcpy(req[i].itemName, req[j].itemName);
               strcpy(req[j].itemName, temp);

	       req[i].QtyInStock = req[i].QtyInStock + req[j].QtyInStock;
	       req[j].QtyInStock = req[i].QtyInStock - req[j].QtyInStock;
	       req[i].QtyInStock = req[i].QtyInStock - req[j].QtyInStock;

	       temp1 = req[i].itemCode;
	       req[i].itemCode = req[j].itemCode;
	       req[j].itemCode = temp1;

	       req[i].price = req[i].price + req[j].price;
	       req[j].price = req[i].price - req[j].price;
	       req[i].price = req[i].price - req[j].price;   
	}
      }
      temp1 = req[pivot].itemCode;
      req[pivot].itemCode = req[j].itemCode;
      req[j].itemCode = temp;

      strcpy(temp, req[pivot].itemName);
      strcpy(req[pivot].itemName, req[j].itemName);
      strcpy(req[j].itemName, temp);

      req[pivot].QtyInStock = req[pivot].QtyInStock + req[j].QtyInStock;
      req[j].QtyInStock = req[pivot].QtyInStock - req[j].QtyInStock;
      req[pivot].QtyInStock = req[pivot].QtyInStock - req[j].QtyInStock;
 
      req[pivot].price = req[pivot].price + req[j].price;
      req[j].price = req[pivot].price - req[j].price;
      req[pivot].price = req[pivot].price - req[j].price;   

      quicksort(req->itemCode, j + 1, last);
      quicksort(req->itemCode, first, j - 1);

    }
}
