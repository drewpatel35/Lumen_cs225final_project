if(EXISTS "/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/build/test_tests-b12d07c.cmake")
  include("/workspaces/cs225/MPs/release-f22/Lumen_cs225final_project-main/build/test_tests-b12d07c.cmake")
else()
  add_test(test_NOT_BUILT-b12d07c test_NOT_BUILT-b12d07c)
endif()
