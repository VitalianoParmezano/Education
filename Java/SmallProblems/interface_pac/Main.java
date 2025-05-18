package interface_pac;

//import ~/Education/Java/SmallProblems


public class Main{

    public static void main(String[] args){
       CardPay card = new CardPay();
       CashPay cash = new CashPay();

       cash.pay(1123);
       cash.pay(123);
       cash.pay(113);
       card.pay(5);
       card.pay(57);
       card.pay(843);

    }

}
