#include "db.hpp"
#include "httplib.h"
#include<regex>

#define WWWROOT "./www"

blog_system::TableUser   *table_user;
blog_system::TableTag    *table_tag;
blog_system::TableBlog   *table_blog;

void InsertUser(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"插入用户\n";
  //用户信息在req的body中，是一个Josn字符串
  //1.获取Json字符串
  std::string json_str = req.body;
  //2.将Json解析到Json::Value对象中
  Json::Reader reader;
  Json::Value root;
  bool ret = reader.parse(json_str, root);
  if(ret == false) {
    printf("insert user info parse json failed!\n");
    rsp.status = 400;
    return;
  }
  //3.调用插入接口插入到数据库
  ret = table_user->Insert(root);
  if(ret == false)
  {
    printf("insetr user into db failed!\n");
    rsp.status = 500;
    return;
  }
  //4.填充rsp响应信息
  rsp.status = 200;
  return;
}

void DeleteUser(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"删除用户\n";
  //获取用户id  /user/id   /user/(\d+)
  int user_id = std::stoi(req.matches[1]);//matches[0]是整个字符串， 剩下的事捕捉的字符串
  //执行数据库操作
  bool ret = table_user->Delete(user_id);
  if(ret == false) {
    printf("delete user failed!\n");
    rsp.status = 500;
    return;
  }
  //填充相应
  rsp.status = 200;
  return;
}

void UpdateUser(const httplib::Request &req, httplib::Response &rsp) { 
  std::cout<<"更新用户\n";
  int user_id = std::stoi(req.matches[1]);
  std::string json_str = req.body;
  Json::Reader reader;
  Json::Value root;
  bool ret = reader.parse(json_str, root);
  if(ret == false) {
    printf("user updata info json failed!\n");
    rsp.status = 400;
    return;
  }
  ret = table_user->Update(user_id, root);
  if(ret == false) {
    printf("update user failed!\n");
    rsp.status = 500;
    return;
  }
  rsp.status = 200;
  return;
}

void GetAllUser(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"获取所有用户\n";
  //从数据库获取所有json用户信息
  Json::Value root;
  bool ret = table_user->GetAll(&root);
  if(ret == false) {
    printf("getall user from db failed!\n");
    rsp.status = 500;
    return;
  }

  //转换为json字符串填充到正文
  Json::FastWriter writer;
  std::string body;
  body = writer.write(root);
  rsp.set_content(body.c_str(), body.size(), "application/json");
  return;
}

void GetOneUser(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"获取单个用户\n";
  int user_id = std::stoi(req.matches[1]);
  Json::Value root;
  bool ret = table_user->GetOne(user_id, &root);
  if(ret == false) {
    printf("getone user from db failed!\n");
    rsp.status = 500;
    return;
  }

  Json::FastWriter writer;
  std::string body = writer.write(root);
  rsp.set_content(body, "application/json");
  return;
}


void InsertTag(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"插入标签\n";
  std::string json_str = req.body;
  Json::Reader reader;
  Json::Value root;
  bool ret = reader.parse(json_str, root);
  if(ret == false) {
    printf("tag into parse failed!\n");
    rsp.status = 400;
    return;
  }
  ret = table_tag->Insert(root);
  if(ret == false) {
    printf("tag into from db failed!\n");
    rsp.status = 500;
    return;
  }
  rsp.status = 200;
  return;
}

void DeleteTag(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"删除标签\n";
  int tag_id = std::stoi(req.matches[1]);
  bool ret = table_tag->Delete(tag_id);
  if(ret == false) {
    printf("delete tag failed!\n");
    rsp.status = 500;
    return;
  }
  rsp.status = 200;
  return;
}

void UpdateTag(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"更新标签\n";
  int tag_id = std::stoi(req.matches[1]);
  std::string json_str = req.body;
  Json::Reader reader;
  Json::Value root;
  bool ret = reader.parse(json_str, root);
  if(ret == false) {
    printf("tag update parse failed!\n");
    rsp.status = 400;
    return;
  }

  ret = table_tag->Update(tag_id, root);
  if(ret == false) {
    printf("upatate tag into failed\n");
    rsp.status = 500;
    return;
  }
  rsp.status = 200;
  return;
}

void GetAllTag(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"获取所有标签\n";
  Json::Value root;
  bool ret = table_tag->GetAll(&root);
  if(ret == false) {
    printf("getall tag failed!\n");
    rsp.status = 500;
    return;
  }
  std::string body;
  Json::FastWriter writer;
  body = writer.write(root);
  rsp.set_content(body, "application/json");
  return;
}

void GetOneTag(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"获取单个标签\n";
  int tag_id = std::stoi(req.matches[1]);
  Json::Value root;
  bool ret = table_tag->GetOne(tag_id, &root);
  if(ret == false) {
    printf("getone tag db failed!\n");
    rsp.status = 500;
    return;
  }
  Json::FastWriter writer;
  std::string body;
  body = writer.write(root);
  rsp.set_content(body, "application/json");
  return;
}


void InsertBlog(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"插入博客\n";
  std::string json_str = req.body;
  Json::Value root;
  Json::Reader reader;
  bool ret = reader.parse(json_str, root);
  if(ret == false) {
    printf("insert into blog parse failed!\n");
    rsp.status = 400;
    return;
  }

  ret = table_blog->Insert(root);
  if(ret == false) {
    printf("insert into from blog failed!\n");
    rsp.status = 500;
    return;
  }
  rsp.status = 200;
  return;
}

void DeleteBlog(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"删除博客\n";
  int bolg_id = std::stoi(req.matches[1]);
  bool ret = table_blog->Delete(bolg_id);
  if(ret == false) {
    printf("delete blog failed!\n");
    rsp.status = 500;
    return;
  }
  rsp.status = 200;
  return;
}

void UpdateBlog(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"更新博客\n"; 
  int blog_id = std::stoi(req.matches[1]);
  std::string json_str = req.body;
  Json::Reader reader;
  Json::Value root;
  bool ret = reader.parse(json_str, root);
  if(ret == false) {
    printf("update blog parse failed!\n");
    rsp.status = 400;
    return;
  }

  ret = table_blog->Update(blog_id, root);
  if(ret == false) {
    printf("update blog from db failed!\n");
    rsp.status = 500;
    return;
  }
  rsp.status = 200;
  return;
}

void GetAllBlog(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"获取所有博客\n";
  //blog 获取所有博客 /blog?tag_id = id 获取标签博客  /blog?user_id = id 获取获取用户博客
  Json::Value root;
  if(req.has_param("tag_id")) {
    int tag_id = std::stoi(req.get_param_value("tag_id"));  
    bool ret = table_blog->GetTag(tag_id, &root);
    if(ret == false) {
      printf("getall tag_id from db failed!\n");
      rsp.status = 500;
      return;
    }
  }
    else if(req.has_param("user_id")) {
      int user_id = std::stoi(req.get_param_value("user_id"));
      bool ret = table_blog->GetUser(user_id, &root);
      if(ret == false) {
        printf("getall user_id grom db failed!\n");
        rsp.status = 500;
        return;
      }
    }
    else {
      bool ret = table_blog->GetAll(&root);
      if(ret == false) {
        printf("getall blog failed!\n");
        rsp.status = 500;
        return;
      }
    }
    Json::FastWriter writer;
    std::string body;
    body = writer.write(root);
    rsp.set_content(body, "application/json");
    return;
}

void GetOneBlog(const httplib::Request &req, httplib::Response &rsp) {
  std::cout<<"获取单个博客\n";
  Json::Value root;
  int blog_id = std::stoi(req.matches[1]);
  bool ret = table_blog->GetOne(blog_id, &root);
  if(ret == false) {
    printf("getone blog fron db failed!\n");
    rsp.status = 500;
    return;
  }

  Json::FastWriter writer;
  rsp.set_content(writer.write(root), "application/json");
  return;
}
int main()
{
  MYSQL *mysql = blog_system::MysqlInit();
  if(mysql == NULL) {
    return -1;
  }

  table_blog = new blog_system::TableBlog(mysql);
  table_user = new blog_system::TableUser(mysql);
  table_tag = new blog_system::TableTag(mysql);

  httplib::Server server;
  //httplib::Server::set_base_dir()设置url中的资源路径的相对根目录
  //httplib会对进行自动读取相应
  server.set_base_dir(WWWROOT);
  //R"()"---括号中原始数据，去除字符特殊含义
  //使用正则表达式匹配符合某种特定格式字符串
  server.Post(R"(/user)", InsertUser);
  server.Delete(R"(/user/(\d+))", DeleteUser);
  server.Put(R"(/user/(\d+))", UpdateUser);
  server.Get(R"(/user)", GetAllUser);
  server.Get(R"(/user/(\d+))", GetOneUser);

  server.Post(R"(/tag)", InsertTag);
  server.Delete(R"(/tag/(\d+))", DeleteTag);
  server.Put(R"(/tag/(\d+))", UpdateTag);
  server.Get(R"(/tag)", GetAllTag);
  server.Get(R"(/tag/(\d+))", GetOneTag);

  server.Post(R"(/blog)", InsertBlog);
  server.Delete(R"(/blog/(\d+))", DeleteBlog);
  server.Put(R"(/blog/(\d+))", UpdateBlog);
  server.Get(R"(/blog)", GetAllBlog);
  server.Get(R"(/blog/(\d+))", GetOneBlog);


  server.listen("0.0.0.0", 9000);
  blog_system::MysqlRelease(mysql);
  return 0;
}
