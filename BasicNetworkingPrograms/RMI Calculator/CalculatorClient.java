import java.rmi.Naming;
import java.rmi.RemoteException;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.rmi.NotBoundException;

public class CalculatorClient {

    public static void main(String[] args) throws NumberFormatException, IOException {
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        try {
            Calculator c = (Calculator)Naming.lookup("rmi://localhost/CalculatorService");
            System.out.println("1-add 2-sub 3-mul 4-div");
            System.out.println("ENTER YOUR CHOICE:");
            int x=Integer.parseInt(br.readLine());
            switch(x)
            {
            case 1:
                System.out.println("enter two numbers:");
                int y=Integer.parseInt(br.readLine());
                int z=Integer.parseInt(br.readLine());
                System.out.println(c.add(y,z));
                  break;
            case 2:
                System.out.println("enter two numbers:");
                 y=Integer.parseInt(br.readLine());
                 z=Integer.parseInt(br.readLine());
                System.out.println(c.sub(y,z));
                 break;
              case 3:
                   {
                System.out.println("enter two numbers:");
                 y=Integer.parseInt(br.readLine());
                 z=Integer.parseInt(br.readLine());
                System.out.println(c.mul(y,z));
                break;
                    }
            case 4:
                System.out.println("enter two numbers:");
                 y=Integer.parseInt(br.readLine());
                 z=Integer.parseInt(br.readLine());
                System.out.println(c.div(y,z));
                break;
              default:
                System.out.println("you havn't entered anything");
                break;
            }
        }
        catch (MalformedURLException murle) {
            System.out.println();
            System.out.println(
              "MalformedURLException");
            System.out.println(murle);
        }
        catch (RemoteException re) {
            System.out.println();
            System.out.println("RemoteException");
            System.out.println(re);
        }
        catch (NotBoundException nbe) {
            System.out.println();
            System.out.println("NotBoundException");
            System.out.println(nbe);
        }
        catch (java.lang.ArithmeticException ae) {
            System.out.println();
            System.out.println(
             "java.lang.ArithmeticException");
            System.out.println(ae);
          
        }
    }
}

