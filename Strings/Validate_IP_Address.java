import java.util.regex.*;


class Validate_IP_address {
    private static final String IPV4_DUMP = "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])";
    private static final String IPV4 = "^" + IPV4_DUMP + "(\\." + IPV4_DUMP +"){3}$";
    private static final String IPV6 = "([0-9a-fA-F]{1,4})(:([0-9a-fA-F]{1,4})){7}";


    public String validIPAddress(String queryIP) {
        int numSections = queryIP.trim().split("[\\.:]").length;
        String output = (numSections==4) ? "IPv4" : (numSections==8) ? "IPv6" : "Neither";
        
        if(!output.equals("Neither")) {
            boolean matches = Pattern.matches((numSections > 4) ? IPV6 : IPV4, queryIP);
            if(!matches) {
                output = "Neither";
            }
        }

        return output;
    }
}
