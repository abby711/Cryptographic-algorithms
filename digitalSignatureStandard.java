import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.Signature;
import sun.misc.BASE64Encoder;
public class DigSign {
public static void main(String[] args) throws Exception {
KeyPairGeneratorkpg = KeyPairGenerator.getInstance("RSA");
kpg.initialize(1024);
KeyPairkeyPair = kpg.genKeyPair();
byte[] data = "Sample Text".getBytes("UTF8");
Signature sig = Signature.getInstance("MD5WithRSA");
sig.initSign(keyPair.getPrivate());
sig.update(data);
byte[] signatureBytes = sig.sign();
System.out.println("Signature: \n" + new BASE64Encoder().encode(signatureBytes));
sig.initVerify(keyPair.getPublic());
sig.update(data);
System.out.println(sig.verify(signatureBytes));
} }
