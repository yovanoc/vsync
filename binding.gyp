{
  "targets": [
    {
      "target_name": "osync",
      "sources": [ "osync.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}