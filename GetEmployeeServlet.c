package cse5c8;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet(&quot;/getEmployeeServlet&quot;)
public class GetEmployeeServlet extends HttpServlet {

protected void doGet(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException {

response.setContentType(&quot;text/plain&quot;);
PrintWriter out = response.getWriter();

try {
EmployeeDAO dao = new EmployeeDAO();
List&lt;Employee&gt; list = dao.getAllEmployees();

if (list.isEmpty()) {
out.println(&quot;No employees found in table&quot;);
return;

}
out.println(&quot;Database selected: 5c8&quot;);
out.println(&quot;EID | ENAME | SALARY | AGE&quot;);

for (Employee e : list) {
out.println(
e.getEid() + &quot; | &quot; +
e.getEname() + &quot; | &quot; +
e.getSalary() + &quot; | &quot; +
e.getAge()
);
}

} catch (Exception e) {
out.println(&quot;Error: &quot; + e.getMessage());
}
}
}
