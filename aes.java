
import java.util.Base64;
import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

public class aes {
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
        String result="";
        try{
            Cipher c=Cipher.getInstance("AES/CBC/PKCS5PADDING");
            byte [] key="ABCDEFGHIJKLMNOP".getBytes("UTF-8");
            SecretKeySpec sp=new SecretKeySpec(key,"AES");
            IvParameterSpec i=new IvParameterSpec(key);
            c.init(Cipher.ENCRYPT_MODE,sp,i);
            Base64.Encoder e=Base64.getEncoder();
            byte[] cipherText=c.doFinal(pt.getBytes("UTF8"));
            result=e.encodeToString(cipherText);    
        }
        catch(Exception e){}
        return result;
    }
    
    public static String decrypt(String pt)
    {
        String result="";
        try{
            Cipher c=Cipher.getInstance("AES/CBC/PKCS5PADDING");
            byte [] key="ABCDEFGHIJKLMNOP".getBytes("UTF-8");
            SecretKeySpec sp=new SecretKeySpec(key,"AES");
            IvParameterSpec i=new IvParameterSpec(key);
            c.init(Cipher.DECRYPT_MODE,sp,i);
            Base64.Decoder d=Base64.getDecoder();
            byte[] cipherText=d.decode(pt);
            result=new String(c.doFinal(cipherText));
         }
        catch(Exception e){}
        return result;
    }
    
}
