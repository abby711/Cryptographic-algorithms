
import java.security.spec.KeySpec;
import java.util.Base64;
import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESedeKeySpec;

public class des {
   public static void main(String [] args)
    {
        String pt="Hello";
        String cipher=encrypt(pt);
        String decipher=decrypt(cipher);
        System.out.println("Encrytion =>"+cipher);
                System.out.println("Decrytion =>"+decipher);    
    }
    
   public static String encrypt(String pt)
   {
       String res="";
       try{
           Cipher c=Cipher.getInstance("DESede");
           byte[] key="ThisIsSecretEncryptionKey".getBytes("UTF8");
           SecretKeyFactory skf=SecretKeyFactory.getInstance("DESede");
           KeySpec ks=new DESedeKeySpec(key);
           SecretKey k=skf.generateSecret(ks);
           c.init(Cipher.ENCRYPT_MODE, k);
           Base64.Encoder e=Base64.getEncoder();
           byte[] ct=c.doFinal(pt.getBytes("UTF8"));
           res=e.encodeToString(ct);
        }
       catch(Exception ex){System.out.println(ex);}
       return res;
   }
        
    
    
    public static String decrypt(String pt)
    {
        String res="";
       try{
           Cipher c=Cipher.getInstance("DESede");
           byte[] key="ThisIsSecretEncryptionKey".getBytes("UTF8");
           SecretKeyFactory skf=SecretKeyFactory.getInstance("DESede");
           KeySpec ks=new DESedeKeySpec(key);
           SecretKey k=skf.generateSecret(ks);
           c.init(Cipher.DECRYPT_MODE, k);
           Base64.Decoder d=Base64.getDecoder();
           byte[] ct=d.decode(pt);
           res=new String (c.doFinal(ct));
           
       }
       catch(Exception ex){System.out.println(ex);}
       return res;
}
}
