package cse5c8;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class EmployeeDAO {

private Connection getConnection() throws Exception {

Class.forName(&quot;com.mysql.cj.jdbc.Driver&quot;);

return DriverManager.getConnection(
&quot;jdbc:mysql://localhost:3306/5c8&quot;,
&quot;root&quot;,
&quot;1234&quot;
);
}

public int insert(Employee e) {

int status = 0;

try {
Connection con = getConnection();

Statement st = con.createStatement();

String sql =
&quot;INSERT INTO employee VALUES (&quot; +
e.getEid() + &quot;, &#39;&quot; +
e.getEname() + &quot;&#39;, &quot; +
e.getSalary() + &quot;, &quot; +
e.getAge() + &quot;)&quot;;

status = st.executeUpdate(sql);

con.close();

} catch (Exception ex) {
ex.printStackTrace();
}

return status;
}

public List&lt;Employee&gt; getAllEmployees() {

List&lt;Employee&gt; list = new ArrayList&lt;&gt;();

try {
Connection con = getConnection();
Statement st = con.createStatement();

ResultSet rs = st.executeQuery(&quot;SELECT * FROM employee&quot;);

while (rs.next()) {
Employee e = new Employee();

e.setEid(rs.getInt(&quot;eid&quot;));
e.setEname(rs.getString(&quot;ename&quot;));
e.setSalary(rs.getInt(&quot;salary&quot;));
e.setAge(rs.getInt(&quot;age&quot;));

list.add(e);
}

con.close();

} catch (Exception ex) {
ex.printStackTrace();
}

return list;
}

public int deleteEmployee(int eid) {

int status = 0;

try {
Connection con = getConnection();

Statement st = con.createStatement();

String sql = &quot;DELETE FROM employee WHERE eid=&quot; + eid;

status = st.executeUpdate(sql);

con.close();

} catch (Exception ex) {
ex.printStackTrace();
}

return status;
}

public int updateEmployee(Employee e) {

int status = 0;

try {
Connection con = getConnection();
Statement st = con.createStatement();

String sql =
&quot;UPDATE employee SET &quot; +
&quot;ename=&#39;&quot; + e.getEname() + &quot;&#39;, &quot; +
&quot;salary=&quot; + e.getSalary() + &quot;, &quot; +
&quot;age=&quot; + e.getAge() +

&quot; WHERE eid=&quot; + e.getEid();

status = st.executeUpdate(sql);

con.close();

} catch (Exception ex) {
ex.printStackTrace();
}

return status;
}
}
