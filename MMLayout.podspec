Pod::Spec.new do |spec|
  spec.name         = 'MMLayout'
  spec.version      = '0.1.0'
  spec.license      =  { :type => 'BSD' }
  spec.homepage     = 'https://github.com/annidy/MMLayout'
  spec.authors      = { 'annidy' => 'annidy@gmail.com' }
  spec.summary      = 'Simple frame layout for iOS.'
  spec.description  = <<-DESC
                      Better frame layout than use setFrame.
                      DESC
  spec.source       = { :git => 'https://github.com/annidy/MMLayout.git', :tag => "v#{spec.version.to_s}" }
  spec.source_files = '*.{h,m}'
  spec.requires_arc = true

  spec.ios.deployment_target = '6.0'
end